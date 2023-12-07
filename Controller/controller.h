#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Model/paintcontroller.h"
#include "../Model/model.h"
#include "../Model/propdealer.h"
#include "action.h"
#include "statecollection.h"


class IController{
public:
//    virtual void createItem (int x, int y) = 0;
    virtual IPaintController* getPaintController() = 0;
    virtual IAction* getAction() = 0;
    virtual StateCollection* getCollection() = 0;
    virtual void setModel(IModel *newModel) = 0;
    virtual void ChangeProps(int width, int index, QColor lineColor, QColor fillColor) = 0;
};


class Controller : public IController
{
public:
    Controller(IModel *newModel);
    IPaintController* getPaintController() override;
    IAction* getAction() override;
    StateCollection* getCollection() override;
    void ChangeProps(int width, int index, QColor lineColor, QColor fillColor) override;
    void setModel(IModel *newModel) override;
//    void ChangeProps() override;
private:
    IModel *model;
    Action *action;
    StateCollection *stateCollection;
    PropDealer *propdealer;
//    IPaintController *paintController;
//    IFactory *factory;
//    StateCollection *collecton;
};

#endif // CONTROLLER_H
