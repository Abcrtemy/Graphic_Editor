#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/paintcontroller.h"
#include "../Model/model.h"
#include "action.h"
#include "statecollection.h"


class IController{
public:
//    virtual void createItem (int x, int y) = 0;
    virtual IPaintController* getPaintController() = 0;
    virtual IAction* getAction() = 0;
    virtual StateCollection* getCollection() = 0;
    virtual void setModel(IModel *newModel) = 0;
};


class Controller : public IController
{
public:
    Controller(IModel *newModel);
    IPaintController* getPaintController() override;
    IAction* getAction() override;
    StateCollection* getCollection() override;
    void setModel(IModel *newModel) override;
private:
    IModel *model;
    Action *action;
    StateCollection *stateCollection;
};

#endif // CONTROLLER_H
