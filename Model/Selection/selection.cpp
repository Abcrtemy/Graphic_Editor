#include "selection.h"
#include "../group.h"

Selection::Selection()
{

}
LineSelection::LineSelection(GrObject *obj){
    object = obj;

}
void LineSelection::Draw(Painter *pntr){
    pntr->drawSelect(object->frame->x1,object->frame->y1);
    pntr->drawSelect(object->frame->x2,object->frame->y2);
}
bool LineSelection::tryGrab(int x, int y){
    if ((x >= object->frame->x2-5 & x <= object->frame->x2+5) &(y >= object->frame->y2-5 & y <= object->frame->y2+5)){
        xToGrab = object->frame->x2;
        yToGrab = object->frame->y2;
        return true;
    }
    else if ((x >= object->frame->x1-5 & x <= object->frame->x1+5) &(y >= object->frame->y1-5 & y <= object->frame->y1+5)){
        xToGrab = object->frame->x1;
        yToGrab = object->frame->y1;
        return true;
    }
    else{
        return false;
    }
}
bool LineSelection::tryMove(int x, int y){
//    object->frame->x2 = x;
//    object->frame->y2 = y;

    if(xToGrab == object->frame->x2 & yToGrab == object->frame->y2){
        object->frame->x2 = x;
        object->frame->y2 = y;
        xToGrab = x;
        yToGrab = y;
    }
    else if(xToGrab == object->frame->x1 & yToGrab == object->frame->y1){
        object->frame->x1 = x;
        object->frame->y1 = y;
        xToGrab = x;
        yToGrab = y;
    }
}
void LineSelection::Release(){

}
void LineSelection::mooveFigure(int x, int y) {
    object->frame->x2 += x;
    object->frame->y2 += y;
    object->frame->x1 += x;
    object->frame->y1 += y;
}


RectSelection::RectSelection(GrObject *obj){
    object = obj;
}
void RectSelection::Draw(Painter *pntr){
    pntr->drawSelect(object->frame->x1,object->frame->y1);
    pntr->drawSelect(object->frame->x1 + object->frame->x2,object->frame->y1);
    pntr->drawSelect(object->frame->x1,object->frame->y1 + object->frame->y2);
    pntr->drawSelect(object->frame->x1 + object->frame->x2,object->frame->y1 + object->frame->y2);
}
bool RectSelection::tryGrab(int x, int y){
    if ((x >= object->frame->x1+object->frame->x2-5 & x <= object->frame->x1+object->frame->x2+5) &(y >= object->frame->y1+object->frame->y2-5 & y <= object->frame->y1+object->frame->y2+5)){
        xToGrab = object->frame->x1 + object->frame->x2;
        yToGrab = object->frame->y1 + object->frame->y2;
        return true;
    }
    else if ((x >= object->frame->x1-5 & x <= object->frame->x1+5) &(y >= object->frame->y1-5 & y <= object->frame->y1+5)){
        xToGrab = object->frame->x1;
        yToGrab = object->frame->y1;
        return true;
    }
    else if ((x >= object->frame->x1+object->frame->x2-5 & x <= object->frame->x1+object->frame->x2+5) &(y >= object->frame->y1-5 & y <= object->frame->y1+5)){
        xToGrab = object->frame->x1 + object->frame->x2;
        yToGrab = object->frame->y1;
        return true;
    }
    else if ((x >= object->frame->x1-5 & x <= object->frame->x1+5) &(y >= object->frame->y1+object->frame->y2-5 & y <= object->frame->y1+object->frame->y2+5)){
        xToGrab = object->frame->x1;
        yToGrab = object->frame->y1 + object->frame->y2;
        return true;
    }
    else {
        return false;
    }
}
bool RectSelection::tryMove(int x, int y){
    if(xToGrab == object->frame->x1 + object->frame->x2 & yToGrab == object->frame->y1 + object->frame->y2){
        object->frame->x2 = x-object->frame->x1;
        object->frame->y2 = y-object->frame->y1;
        xToGrab = object->frame->x2+ object->frame->x1;
        yToGrab = object->frame->y2+ object->frame->y1;
    }
    else if(xToGrab == object->frame->x1 & yToGrab == object->frame->y1){
        int xx = object->frame->x1 + object->frame->x2;
        int yy = object->frame->y1 + object->frame->y2;
        object->frame->x1 = x;
        object->frame->y1 = y;
        object->frame->x2 = xx - object->frame->x1;
        object->frame->y2 = yy - object->frame->y1;
        xToGrab = x;
        yToGrab = y;
    }
    else if(xToGrab == object->frame->x1 + object->frame->x2 & yToGrab == object->frame->y1){
        int yy = object->frame->y1 + object->frame->y2;
        object->frame->x2 = x-object->frame->x1;
        object->frame->y1 = y;
        xToGrab = object->frame->x2 + object->frame->x1;
        object->frame->y2 = yy - object->frame->y1;
        yToGrab = y;
    }
    else if(xToGrab == object->frame->x1 & yToGrab == object->frame->y1 + object->frame->y2){
        int xx = object->frame->x1 + object->frame->x2;
        object->frame->x1 = x;
        object->frame->y2 = y-object->frame->y1;
        object->frame->x2 = xx - object->frame->x1;
        xToGrab = x;
        yToGrab = object->frame->y2 + object->frame->y1;
    }
}
void RectSelection::Release(){

}
void RectSelection::mooveFigure(int x, int y) {
//    object->frame->x2 += x;
//    object->frame->y2 += y;
    object->frame->x1 += x;
    object->frame->y1 += y;
}




GroupSelection::GroupSelection(GrObject *obj){
    object = obj;
}
void GroupSelection::Draw(Painter *pntr){
    pntr->drawSelect(object->frame->x1,object->frame->y1);
    pntr->drawSelect(object->frame->x2,object->frame->y1);
    pntr->drawSelect(object->frame->x1,object->frame->y2);
    pntr->drawSelect(object->frame->x2,object->frame->y2);
}
bool GroupSelection::tryGrab(int x, int y){
    if ((x >= object->frame->x2-5 & x <= object->frame->x2+5) &(y >= object->frame->y2-5 & y <= object->frame->y2+5)){
        xToGrab = object->frame->x2;
        yToGrab = object->frame->y2;
        return true;
    }
    else if ((x >= object->frame->x1-5 & x <= object->frame->x1+5) &(y >= object->frame->y2-5 & y <= object->frame->y2+5)){
        xToGrab = object->frame->x1;
        yToGrab = object->frame->y2;
        return true;
    }
    else if ((x >= object->frame->x1-5 & x <= object->frame->x1+5) &(y >= object->frame->y1-5 & y <= object->frame->y1+5)){
        xToGrab = object->frame->x1;
        yToGrab = object->frame->y1;
        return true;
    }
    else if ((x >= object->frame->x2-5 & x <= object->frame->x2+5) &(y >= object->frame->y1-5 & y <= object->frame->y1+5)){
        xToGrab = object->frame->x2;
        yToGrab = object->frame->y1;
        return true;
    }
    else {
        return false;
    }
}
bool GroupSelection::tryMove(int x, int y){
    int a = x - object->frame->x2;
    int b = y - object->frame->y2;
//    object->frame->x2 = x;
//    object->frame->y2 = y;
    Group *gr = dynamic_cast<Group*>(object);
    gr->refactorCoordinats(a, b);
}
void GroupSelection::Release(){

}
void GroupSelection::mooveFigure(int x, int y) {
    object->frame->x2 += x;
    object->frame->y2 += y;
    object->frame->x1 += x;
    object->frame->y1 += y;
    Group *gr = dynamic_cast<Group*>(object);
    gr->changeCoords(x,y);
}
