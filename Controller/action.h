#ifndef ACTION_H
#define ACTION_H

#include "../Model/model.h"
#include "statecollection.h"
//#include

class IAction{
public:
    //    virtual void createItem (int x, int y) = 0;
    virtual CreateObjectType getCreatedObjectType() = 0;
    virtual void setCreateObjectType(CreateObjectType objectType) = 0;
    virtual void mouseUp(int x, int y) = 0;
    virtual void mouseDown(int x, int y) = 0;
    virtual void mouseMoove(int x, int y) = 0;
    virtual void shiftMouseUp(int x, int y) = 0;
    virtual void esc() = 0;
    virtual void group() = 0;
    virtual void unGroup() = 0;
    virtual void del() = 0;
    virtual void startCreate() = 0;
};

class Action : public IAction
{
public:
    Action(IModel *newModel, StateCollection *state);
    CreateObjectType getCreatedObjectType() override;
    void setCreateObjectType(CreateObjectType objectType) override;
    void mouseUp(int x, int y) override;
    void mouseDown(int x, int y) override;
    void mouseMoove(int x, int y) override;
    void shiftMouseUp(int x, int y) override;
    void esc() override;
    void del() override;
    void group() override;
    void unGroup() override;
    void startCreate() override;
private:
    IModel *model;
    IFactory *factory;
    StateCollection *collection;

//    ISelectionDealler *dealer;
};

#endif // ACTION_H
