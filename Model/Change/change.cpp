#include "change.h"

Change::Change()
{

}


CreateChange::CreateChange(GrObject *obj, ObjectStore *objStore){
    object = obj;
    objectStore = objStore;
}

void CreateChange::doAction(){
    int counter = 0;
    for(int i = 0; i< objectStore->length(); i ++){
        if (objectStore->value(i)==object){
            objectStore->removeAt(i);
            counter ++;
        }
    }
    if (counter == 0){
        objectStore->append(object);
    }
}

TransformChange::TransformChange(GrObject *obj,Frame *fr){
    object = obj;
    frame = fr;
}

void TransformChange::doAction(){

    if(dynamic_cast<Group*>(object)){
        Group *grop = dynamic_cast<Group*>(object);
        if((object->frame->x1 - frame->x1) == (object->frame->x2 - frame->x2)){
            grop->changeCoords((frame->x1 - object->frame->x1 ), (frame->y1 - object->frame->y1));
        }
        else{
            grop->refactorCoordinats(frame->x2-object->frame->x2,frame->y2 - object->frame->y2);
        }
    }
    object->frame = frame;

}

GroupChange::GroupChange(Group *gr, ObjectStore *objStore, GroupDealler *grDealler){
    group = gr;
    groupDealler = grDealler;
    objectStore = objStore;
    list = group->getList();
}

void GroupChange::doAction(){
    int counter = 0;
    for(int i = 0; i< objectStore->length(); i ++){
        if (objectStore->value(i)==group){
            for (int j = 0; j <list->length(); j ++){
                objectStore->append(list->value(j));
            }
            objectStore->removeAt(i);
            counter ++;
        }
    }
    if (counter == 0){
        for(int i = 0; i< objectStore->length(); i ++){
            for (int j = 0; j <list->length(); j ++){
                if (objectStore->value(i)==list->value(j)){
                    objectStore->removeAt(i);
                    i--;
                }
            }
        }
        objectStore->append(group);
    }
}
