#ifndef CHANGE_H
#define CHANGE_H
#include "../grobject.h"
#include "../frame.h"
#include "../group.h"
#include "../objectstore.h"
#include "../groupdealler.h"

class Change
{
public:
    Change();
    virtual void doAction() = 0;
};


class CreateChange : public Change
{
public:
    CreateChange(GrObject *obj, ObjectStore *objStore);
    void doAction() override;
private:
    GrObject *object;
    ObjectStore *objectStore;
};

class TransformChange : public Change
{
public:
    TransformChange(GrObject *obj, Frame *fr);
    void doAction() override;
private:
    GrObject *object;
    Frame *frame;
};

class GroupChange : public Change
{
public:
    GroupChange(Group *gr, ObjectStore *objStore, GroupDealler *grDealler);
    void doAction() override;
private:
    Group *group;
    ObjectStore *objectStore;
    GroupDealler *groupDealler;
    QList<GrObject*> *list;
};

#endif // CHANGE_H
