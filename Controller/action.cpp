#include "action.h"

Action::Action(IModel *newModel, StateCollection *state)
{
    model = newModel;
    factory = model->getFactory();
    collection = state;
}


void Action::setCreateObjectType(CreateObjectType objectType){
    factory->setType(objectType);
}

void Action::mouseUp(int x, int y){
    collection->mouseUp(x,y);

}
void Action::mouseDown(int x, int y){
    collection->mouseDown(x,y);
}

void Action::mouseMoove(int x, int y){
    collection->mouseMoove(x,y);
}


void Action::startCreate(){
    collection->startCreate();
}

void Action::shiftMouseUp(int x, int y){
    collection->shiftMouseUp(x, y);
}
void Action::esc(){
    collection->esc();
}
void Action::del(){
    collection->del();
}
void Action::group(){
    collection->group();
}
void Action::unGroup(){
    collection->unGroup();
}

void Action::undo(){
    collection->undo();
}
void Action::redo(){
    collection->redo();
}

CreateObjectType Action::getCreatedObjectType(){
    return factory->getType();
}
