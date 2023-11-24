#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/paintcontroller.h"
#include "../Model/model.h"
#include "action.h"


class IController{
public:
//    virtual void createItem (int x, int y) = 0;
    virtual IPaintController* getPaintController() = 0;
    virtual IAction* getAction() = 0;
    virtual void setModel(IModel *newModel) = 0;
};


class Controller : public IController
{
public:
    Controller(IModel *newModel);
    IPaintController* getPaintController();
    IAction* getAction();
    void setModel(IModel *newModel);
private:
    IModel *model;
    Action *action;
};

#endif // CONTROLLER_H
