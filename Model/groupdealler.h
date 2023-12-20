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
    void unGroup();
private:
    ObjectStore *objStore;
    SelectionStore *selStore;
    Group *groupe;
};

#endif // GROUPDEALLER_H
