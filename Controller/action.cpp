#include "action.h"

Action::Action(IModel *newModel, StateCollection *state)
{
    model = newModel;
    factory = model->getFactory();
    collection = state;
//    dealer = model->getSelectionDealler();
}


void Action::setCreateObjectType(CreateObjectType objectType){
    factory->setType(objectType);
}

void Action::mouseUp(int x, int y){
//    factory = model->getFactory();
//    factory->createItem(x,y);
    collection->mouseUp(x,y);

}
void Action::mouseDown(int x, int y){
    //    factory = model->getFactory();
//    factory->createAndGrabItem(x,y);
    collection->mouseDown(x,y);

//    dealer->SelectAndGrab();
}

void Action::mouseMoove(int x, int y){
    //    factory = model->getFactory();
//    factory->GrabItem(x,y);
    collection->mouseMoove(x,y);
    //    dealer->SelectAndGrab();
}

CreateObjectType Action::getCreatedObjectType(){
    return factory->getType();
}
