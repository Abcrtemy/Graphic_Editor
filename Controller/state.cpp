#include "state.h"

State::State(IModel *nModel)
{
    factory = nModel->getFactory();
    dealler = nModel->getSelectionDealler();
    changeDealler = nModel->getChangeDealler();
}

DragState::DragState(IModel *model): State(model)
{

}

void DragState::MouseMove (int x, int y){
    dealler->tryMoove(x, y);
}
void DragState::MouseUp (int x, int y, std::function<void()> drag, std::function<void()> empty, std::function<void()> single){
    // запомнить frame

    single();
}
void DragState::MouseDown (int x, int y, std::function<void()> callback){

}
void DragState::ShiftMouseUp(int x, int y, std::function<void()> multi){

}
void DragState::esc(std::function<void()> empty){

}
void DragState::del(std::function<void()> empty){

}
void DragState::group(std::function<void()> single){

}
void DragState::unGroup(std::function<void()> multi){

}
void DragState::undo(std::function<void()> empty){

}
void DragState::redo(std::function<void()> empty){

}




CreateState::CreateState(IModel *model): State(model)
{

}
void CreateState::MouseMove (int x, int y){

}
void CreateState::MouseUp (int x, int y, std::function<void()> drag, std::function<void()> empty, std::function<void()> single){

}
void CreateState::MouseDown (int x, int y, std::function<void()> callback){
    factory->createAndGrabItem(x,y);
    dealler->SelectCreated(x,y);
    //добавить в хранилище именений
    callback();
}
void CreateState::ShiftMouseUp(int x, int y, std::function<void()> multi){

}
void CreateState::esc(std::function<void()> empty){

}
void CreateState::del(std::function<void()> empty){

}
void CreateState::group(std::function<void()> single){

}
void CreateState::unGroup(std::function<void()> multi){

}
void CreateState::undo(std::function<void()> empty){

}
void CreateState::redo(std::function<void()> empty){

}




EmptyState::EmptyState(IModel *model): State(model)
{

}
void EmptyState::MouseMove (int x, int y){

}
void EmptyState::MouseUp (int x, int y, std::function<void()> drag, std::function<void()> empty, std::function<void()> single){
    if (dealler->trySelect(x,y) == true){
        single();
    }
}
void EmptyState::MouseDown (int x, int y, std::function<void()> callback){
}
void EmptyState::ShiftMouseUp(int x, int y, std::function<void()> multi){

}
void EmptyState::esc(std::function<void()> empty){

}
void EmptyState::del(std::function<void()> empty){

}
void EmptyState::group(std::function<void()> single){

}
void EmptyState::unGroup(std::function<void()> multi){

}
void EmptyState::undo(std::function<void()> empty){
    changeDealler->undoAction();
}
void EmptyState::redo(std::function<void()> empty){
    changeDealler->redoAction();
}



SingleState::SingleState(IModel *model): State(model)
{

}
void SingleState::MouseMove (int x, int y){
    dealler->mooveFigure(x, y);
    if(amountOfMoovments == 0){
        dealler->rememberCoordinats();
    }
    amountOfMoovments++;
}
void SingleState::MouseUp (int x, int y, std::function<void()> drag, std::function<void()> empty, std::function<void()> single){
    amountOfMoovments = 0;
    if (dealler->trySelect(x,y) == false){
        dealler->Release();
        empty();
    }
}
void SingleState::MouseDown (int x, int y, std::function<void()> callback){
    dealler->globalX = x;
    dealler->globalY = y;
    if (dealler->tryGrab(x, y)){
        dealler->rememberCoordinats();
        callback();
//        dealler->rememberCoordinats();
    }
}
void SingleState::ShiftMouseUp(int x, int y, std::function<void()> multi){
    if(dealler->addSelection(x, y) == true){
        multi();
    }

}
void SingleState::esc(std::function<void()> empty){
    dealler->Release();
    empty();
}
void SingleState::del(std::function<void()> empty){
    dealler->del();
    empty();
}
void SingleState::group(std::function<void()> single){

}
void SingleState::unGroup(std::function<void()> multi){
//    sdfsdfvdfv
    dealler->unGroup();
    multi();
}
void SingleState::undo(std::function<void()> empty){
    changeDealler->undoAction();
    dealler->Release();
    empty();
}
void SingleState::redo(std::function<void()> empty){
    changeDealler->redoAction();
    dealler->Release();
    empty();
}




MultiState::MultiState(IModel *model): State(model)
{

}
void MultiState::MouseMove (int x, int y){
    dealler->mooveFigure(x, y);
}
void MultiState::MouseUp (int x, int y, std::function<void()> drag, std::function<void()> empty, std::function<void()> single){
    if (dealler->trySelect(x,y) == false){
        dealler->Release();
        empty();
    }
}
void MultiState::MouseDown (int x, int y, std::function<void()> callback){
    dealler->globalX = x;
    dealler->globalY = y;
}
void MultiState::ShiftMouseUp(int x, int y, std::function<void()> multi){
    dealler->addSelection(x,y);
}
void MultiState::esc(std::function<void()> empty){
    dealler->Release();
    empty();
}
void MultiState::del(std::function<void()> empty){
    dealler->del();
    empty();
}
void MultiState::group(std::function<void()> single){
    //sdfsdf
    factory->createGroup();
    dealler->group();
    single();
}
void MultiState::unGroup(std::function<void()> multi){

}
void MultiState::undo(std::function<void()> empty){
    changeDealler->undoAction();
    dealler->Release();
    empty();
}
void MultiState::redo(std::function<void()> empty){
    changeDealler->redoAction();
    dealler->Release();
    empty();
}
