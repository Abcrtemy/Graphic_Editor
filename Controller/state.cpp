#include "state.h"

State::State(IAction *newAction)
{
    action = newAction;
}

DragState::DragState(IAction *newAction): State(newAction)
{

}

void DragState::MouseMove (int x, int y){

}
void DragState::MouseUp (int x, int y){
    action->mouseUp(x, y);
}
void DragState::MouseDown (int x, int y){

}

CreateState::CreateState(IAction *newAction): State(newAction)
{

}

void CreateState::MouseMove (int x, int y){

}
void CreateState::MouseUp (int x, int y){

}
void CreateState::MouseDown (int x, int y){
    action->mouseDown(x, y);
}
