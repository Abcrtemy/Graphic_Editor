#include "controller.h"

Controller::Controller(IModel* newModel)
{
    model = newModel;
    action = new Action(model);
    stateCollection = new StateCollection(action);
}

void Controller::setModel(IModel* newModel){
    model = newModel;
}

IPaintController* Controller::getPaintController(){
    return model->getPaintController();
}
IAction* Controller::getAction(){
    return action;
}

StateCollection* Controller::getCollection(){
    return stateCollection;
}
