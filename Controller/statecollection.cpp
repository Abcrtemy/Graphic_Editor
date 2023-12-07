#include "statecollection.h"

StateCollection::StateCollection(IModel *model)
{

    dragState = new DragState(model);
    createState = new CreateState(model);
    this->append(createState);
    this->append(dragState);
    nowState = crState;
}

void StateCollection::mouseUp(int x, int y){
    if (nowState == crState){
        this->value(0)->MouseUp(x,y);
        nowState = drState;
    }
    else {
        this->value(1)->MouseUp(x,y);
        nowState = crState;
    }

}

void StateCollection::mouseDown(int x, int y){
    if (nowState == crState){
        this->value(0)->MouseDown(x,y);
        nowState = drState;
    }
    else {
        this->value(1)->MouseDown(x,y);
        nowState = crState;
    }
}
void StateCollection::mouseMoove(int x, int y){
    if (nowState == crState){
        this->value(0)->MouseMove(x,y);
//        nowState = drState;
    }
    else {
        this->value(1)->MouseMove(x,y);
//        nowState = crState;
    }
}
