#include "state.h"

State::State(IModel *nModel)
{
    factory = nModel->getFactory();
    dealler = nModel->getSelectionDealler();
}

DragState::DragState(IModel *model): State(model)
{

}

void DragState::MouseMove (int x, int y){
    dealler->tryMoove(x, y);
//    emit changeToCreate();
//    callback();
}
void DragState::MouseUp (int x, int y, std::function<void()> callback){
    dealler->Release();
    callback();
}
void DragState::MouseDown (int x, int y, std::function<void()> callback){

}

CreateState::CreateState(IModel *model): State(model)
{

}

void CreateState::MouseMove (int x, int y){

}
void CreateState::MouseUp (int x, int y, std::function<void()> callback){

}
void CreateState::MouseDown (int x, int y, std::function<void()> callback){
//    action->mouseDown(x, y);
    factory->createAndGrabItem(x,y);
    dealler->SelectCreated(x,y);
    callback();
//    emit changeToDrag();
}
