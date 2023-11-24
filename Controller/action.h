#ifndef ACTION_H
#define ACTION_H

#include "../Model/model.h"
//#include

class IAction{
public:
    //    virtual void createItem (int x, int y) = 0;
    virtual CreateObjectType getCreatedObjectType() = 0;
    virtual void setCreateObjectType(CreateObjectType objectType) = 0;
    virtual void mouseUp(int x, int y) = 0;
};

class Action : public IAction
{
public:
    Action(IModel *newModel);
    CreateObjectType getCreatedObjectType();
    void setCreateObjectType(CreateObjectType objectType);
    void mouseUp(int x, int y);
private:
    IModel *model;
    IFactory *factory;
};

#endif // ACTION_H
