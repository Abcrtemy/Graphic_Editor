#include "changedealler.h"

ChangeDealler::ChangeDealler(ChangeStore *chStore, ObjectStore *objStore, GroupDealler *grDealler)
{
    changeStore = chStore;
    objectStore = objStore;
    groupDealler = grDealler;
    currentI = 100;
}

void ChangeDealler::validCheck(){
    for (int i = changeStore->length()-1; i> currentI; i --){
        changeStore->removeAt(i);
    }
    if(changeStore->length() >=20){
        changeStore->removeAt(0);
    }
}

void ChangeDealler::figureChange(GrObject *grObject){
    Change *figChange = new CreateChange(grObject, objectStore);
    validCheck();
    changeStore->append(figChange);
    currentI = changeStore->length()-1;
}

void ChangeDealler::transformChange(GrObject *grObject, Frame *frame){
    Change *transfChange = new TransformChange(grObject, frame);
    validCheck();
    changeStore->append(transfChange);
    currentI = changeStore->length() - 1;
}

void ChangeDealler::groupChange(Group *group){
    Change *grChange = new GroupChange(group, objectStore, groupDealler);
    validCheck();
    changeStore->append(grChange);
    currentI = changeStore->length() - 1;
}

void ChangeDealler::undoAction(){
//    if(currentI >= changeStore->length()){
//        currentI = changeStore->length()-1;
//    }
    if (currentI>=0){
        changeStore->value(currentI)->doAction();
//        changeStore->append(changeStore->value(currentI));
//        changeStore->removeAt(currentI);
        currentI = currentI - 1;
    }


}

void ChangeDealler::redoAction(){

    if (currentI < changeStore->length()-1){
        currentI = currentI + 1;
        changeStore->value(currentI)->doAction();
//        changeStore->append(changeStore->value(currentI));
//        changeStore->removeAt(currentI);

    }


}
