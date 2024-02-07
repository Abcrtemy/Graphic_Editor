#include "statecollection.h"
#include <QAction>

#include <functional>

StateCollection::StateCollection(IModel *model)
{
    dragState = new DragState(model);
    createState = new CreateState(model);
    emptyState = new EmptyState(model);
    multiState = new MultiState(model);
    singleState = new SingleState(model);
    this->append(createState);
    this->append(dragState);
    this->append(emptyState);
    this->append(multiState);
    this->append(singleState);
    nowState = emptyState;
}

void StateCollection::mouseUp(int x, int y){
    std::function<void()> drag = [this](){ changeToDrag(); };
    std::function<void()> empty = [this](){ changeToEmpty(); };
    std::function<void()> single = [this](){ changeToSingle(); };
    nowState->MouseUp(x, y, drag, empty, single);

}

void StateCollection::mouseDown(int x, int y){
    std::function<void()> drag = [this](){ changeToDrag(); };
//    std::function<void()> empty = [this](){ changeToDrag(); };
    nowState->MouseDown(x, y,drag);
}
void StateCollection::mouseMoove(int x, int y){

    nowState->MouseMove(x, y);
}

void StateCollection::shiftMouseUp(int x, int y){
    std::function<void()> multi = [this](){ changeToMulti(); };
    nowState->ShiftMouseUp(x, y, multi);
}

void StateCollection::esc(){
    std::function<void()> empty = [this](){ changeToEmpty(); };
    nowState->esc(empty);
}

void StateCollection::del(){
    std::function<void()> empty = [this](){ changeToEmpty(); };
    nowState->del(empty);
}

void StateCollection::startCreate(){
    changetoCreate();
}

void StateCollection::group(){
    std::function<void()> single = [this](){ changeToSingle(); };
    nowState->group(single);
//    changetoCreate();
}

void StateCollection::unGroup(){
//    changetoCreate();
    std::function<void()> multi = [this](){ changeToMulti(); };
    nowState->unGroup(multi);
}

void StateCollection::undo(){
    std::function<void()> empty = [this](){ changeToEmpty(); };
    nowState->undo(empty);
}

void StateCollection::redo(){
    std::function<void()> empty = [this](){ changeToEmpty(); };
    nowState->redo(empty);
}


void StateCollection::changetoCreate(){
    nowState = createState;
}
void StateCollection::changeToDrag(){
    nowState = dragState;
}
void StateCollection::changeToEmpty(){
    nowState = emptyState;
}
void StateCollection::changeToSingle(){
    nowState = singleState;
}
void StateCollection::changeToMulti(){
    nowState = multiState;
}

