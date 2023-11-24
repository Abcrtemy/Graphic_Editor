#ifndef FACTORY_H
#define FACTORY_H

#include "proplist.h"
#include "figure.h"
#include "frame.h"
#include "objectstore.h"
#include "setofprops.h"


enum CreateObjectType {
    LineType, RectangleType
};


class IFactory{
public:
    virtual void createItem (int x, int y) = 0;
    virtual CreateObjectType getType() = 0;
    virtual void setType(CreateObjectType objectType) = 0;
};

class Factory : public IFactory
{
public:
    Factory(ObjectStore *newStore);
    void createItem (int x, int y) override;
    CreateObjectType getType() override;
    void setType(CreateObjectType objectType) override;

private:
    CreateObjectType createObjectType;
    ObjectStore *store;
//    SetOfProps *props;

};

#endif // FACTORY_H
//Frame *frame, PropList *proplist
