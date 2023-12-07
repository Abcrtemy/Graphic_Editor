#ifndef FACTORY_H
#define FACTORY_H

#include "proplist.h"
#include "figure.h"
#include "frame.h"
#include "objectstore.h"
#include "setofprops.h"
#include "Selection/selectiondealler.h"

enum CreateObjectType {
    LineType, RectangleType
};


class IFactory{
public:
    virtual void createItem (int x, int y) = 0;
    virtual void createAndGrabItem (int x, int y) = 0;
    virtual void GrabItem (int x, int y) = 0;
    virtual CreateObjectType getType() = 0;
    virtual void setType(CreateObjectType objectType) = 0;
    virtual void setLineProps(LineSetOfProps * fillP) = 0;
    virtual void setFillProps(FillSetOfProps * lineP) = 0;
};

class Factory : public IFactory
{
public:
    Factory(ObjectStore *newStore, ISelectionDealler *dealer);
    void createItem (int x, int y) override;
    void createAndGrabItem (int x, int y) override;
    void GrabItem (int x, int y) override;
    CreateObjectType getType() override;
    void setType(CreateObjectType objectType) override;
    void setFillProps(FillSetOfProps * fillP) override;
    void setLineProps(LineSetOfProps * lineP) override;
private:
    CreateObjectType createObjectType;
    ObjectStore *store;
    LineSetOfProps *lineProps;
    FillSetOfProps *fillProps;
    ISelectionDealler *selectionDealer;
    int xx = 100, yy = 100;
};

#endif // FACTORY_H
//Frame *frame, PropList *proplist
