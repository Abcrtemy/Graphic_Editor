#include "action.h"

Action::Action(IModel *newModel)
{
    model = newModel;
    factory = model->getFactory();
//    dealer = model->getSelectionDealler();
}


void Action::setCreateObjectType(CreateObjectType objectType){
    factory->setType(objectType);
}

void Action::mouseUp(int x, int y){
//    factory = model->getFactory();
    factory->createItem(x,y);

}
void Action::mouseDown(int x, int y){
    //    factory = model->getFactory();
    factory->createAndGrabItem(x,y);
//    dealer->SelectAndGrab();
}

CreateObjectType Action::getCreatedObjectType(){
    return factory->getType();
}
