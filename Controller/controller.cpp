#include "controller.h"

Controller::Controller(IModel* newModel)
{
    model = newModel;

    stateCollection = new StateCollection(model);
    action = new Action(model, stateCollection);
    propdealer = new PropDealer(model->getFactory());
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
void Controller::ChangeProps(int width, int index, QColor lineColor, QColor fillColor){
    propdealer->changeProps(width,index,lineColor,fillColor);
}
//QColor newColor, Qt::PenStyle newStyle, int newWit
