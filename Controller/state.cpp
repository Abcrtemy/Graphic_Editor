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
}
void DragState::MouseUp (int x, int y){
    dealler->Release();
}
void DragState::MouseDown (int x, int y){

}

CreateState::CreateState(IModel *model): State(model)
{

}

void CreateState::MouseMove (int x, int y){

}
void CreateState::MouseUp (int x, int y){

}
void CreateState::MouseDown (int x, int y){
//    action->mouseDown(x, y);
    factory->createAndGrabItem(x,y);
}
