#include "action.h"

Action::Action(IModel *newModel)
{
    model = newModel;
    factory = model->getFactory();
}


void Action::setCreateObjectType(CreateObjectType objectType){
    factory->setType(objectType);
}

void Action::mouseUp(int x, int y){
//    factory = model->getFactory();
    factory->createItem(x,y);
}

CreateObjectType Action::getCreatedObjectType(){
    return factory->getType();
}
