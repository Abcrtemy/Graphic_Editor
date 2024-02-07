#ifndef CHANGEDEALLER_H
#define CHANGEDEALLER_H

#include "../grobject.h"
#include"../frame.h"
#include"../group.h"
#include "changestore.h"
#include "change.h"
#include "../groupdealler.h"
#include "../objectstore.h"
//#include ".h"

class ChangeDealler
{
public:
    ChangeDealler(ChangeStore *chStore, ObjectStore *objStore, GroupDealler *grDealler);
    void figureChange(GrObject *grObject);
    void transformChange(GrObject *grObject, Frame *frame);
    void groupChange(Group *group);
    void undoAction();
    void redoAction();
    void validCheck();
    int currentI;
private:
    ChangeStore *changeStore;
    ObjectStore *objectStore;
    GroupDealler *groupDealler;
};

#endif // CHANGEDEALLER_H
