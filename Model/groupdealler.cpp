#include "groupdealler.h"


GroupDealler::GroupDealler(ObjectStore *objectStore, SelectionStore *selectionStore)
{
    objStore = objectStore;
    selStore = selectionStore;
    list = selStore->getObjList();
}


void GroupDealler::group(QList<GrObject*> *list){
    if (list->length()==0){
        return;
    }
    for (int i = objStore->length()-1; i >= 0; i--){
        if (dynamic_cast<Group*>(objStore->value(i))){
            groupe = dynamic_cast<Group*>(objStore->value(i));
            break;
        }
    }
    for(int i = 0; i< list->length(); i++){
        groupe->addToGroup(list->value(i));
    }
    int x = 0;
    int y = 0;
    int x11 = 0;
    int y11 = 0;
    x = list->value(0)->frame->x1;
    y = list->value(0)->frame->y1;
    for(int i = 0; i < list->length(); i++){
        if (dynamic_cast<Line*>(list->value(i)) || dynamic_cast<Group*>(list->value(i))){
            if(std::min(list->value(i)->frame->x1,list->value(i)->frame->x2)< x){
                x = std::min(list->value(i)->frame->x1,list->value(i)->frame->x2);
            }
            if(std::min(list->value(i)->frame->y1,list->value(i)->frame->y2)< y){
                y = std::min(list->value(i)->frame->y1,list->value(i)->frame->y2);
            }
            if(std::max(list->value(i)->frame->x1,list->value(i)->frame->x2)> x11){
                x11 = std::max(list->value(i)->frame->x1,list->value(i)->frame->x2);
            }
            if(std::max(list->value(i)->frame->y1,list->value(i)->frame->y2)> y11){
                y11 = std::max(list->value(i)->frame->y1,list->value(i)->frame->y2);
            }
        }
        else if(dynamic_cast<Rectangle*>(list->value(i))){
            if(std::min(list->value(i)->frame->x1,list->value(i)->frame->x1 + list->value(i)->frame->x2)< x){
                x = std::min(list->value(i)->frame->x1,list->value(i)->frame->x2);
            }
            if(std::min(list->value(i)->frame->y1,list->value(i)->frame->y2)< y){
                y = std::min(list->value(i)->frame->y1,list->value(i)->frame->y2 + list->value(i)->frame->y2);
            }
            if(std::max(list->value(i)->frame->x1,list->value(i)->frame->x2)> x11){
                x11 = std::max(list->value(i)->frame->x1,list->value(i)->frame->x1 + list->value(i)->frame->x2);
            }
            if(std::max(list->value(i)->frame->y1,list->value(i)->frame->y2)> y11){
                y11 = std::max(list->value(i)->frame->y1,list->value(i)->frame->y1 + list->value(i)->frame->y2);
            }
        }
    }
//    for(int i = 0; i < list->length(); i++){
//        if(std::min(list->value(i)->frame->y1,list->value(i)->frame->y2)< y){
//            y = std::min(list->value(i)->frame->y1,list->value(i)->frame->y2);
//        }
//    }
//    for(int i = 0; i < list->length(); i++){
//        if(std::max(list->value(i)->frame->x1,list->value(i)->frame->x2)> x11){
//            x11 = std::max(list->value(i)->frame->x1,list->value(i)->frame->x2);
//        }
//    }
//    for(int i = 0; i < list->length(); i++){
//        if(std::max(list->value(i)->frame->y1,list->value(i)->frame->y2)> y11){
//            y11 = std::max(list->value(i)->frame->y1,list->value(i)->frame->y2);
//        }
//    }
    groupe->frame->x1 = x;
    groupe->frame->x2 = x11;
    groupe->frame->y1 =y;
    groupe->frame->y2 = y11;
    for(int i = 0; i< list->length(); i++){
        for(int j = 0; j< objStore->length(); j++){
            if (objStore->value(j) == list->value(i)){
                objStore->removeAt(j);
            }
        }
    }
    groupe->countKs();
//    list->clear();
//    list->append(this);
//    objStore->removeLast();

//groupDealler->unGroup();
}
void GroupDealler::unGroup(Group *groupe){
    for (int z = list->length()-1; z >= 0; z--){
        if (dynamic_cast<Rectangle*>(list->value(z))){
            Selection *selection = new RectSelection(list->value(z));
            selStore->append(selection);
            selStore->activeSelection = selection;
            objStore->append(list->value(z));
        }
        else if (dynamic_cast<Line*>(list->value(z))){
            Selection *selection = new LineSelection(list->value(z));
            selStore->append(selection);
            selStore->activeSelection = selection;
            objStore->append(list->value(z));
        }
        else if (dynamic_cast<Group*>(list->value(z))){
            Selection *selection = new GroupSelection(list->value(z));
            selStore->append(selection);
            selStore->activeSelection = selection;
            objStore->append(list->value(z));
        }
    }
}
