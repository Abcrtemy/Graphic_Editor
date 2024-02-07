#ifndef GROUPDEALLER_H
#define GROUPDEALLER_H

#include "Selection/selectionstore.h"
#include "objectstore.h"
#include "group.h"


class GroupDealler
{
public:
    GroupDealler(ObjectStore *objectStore, SelectionStore *selectionStore);
    void group(QList<GrObject*> *list);
//    QList<GrObject*> * unGroup();
    void unGroup(Group *group);

private:
    ObjectStore *objStore;
    SelectionStore *selStore;
    Group *groupe;
    QList<GrObject*> *list;
};

#endif // GROUPDEALLER_H
