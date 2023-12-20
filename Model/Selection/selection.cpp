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
        return true;
    }
    else {
        return false;
    }
}
bool LineSelection::tryMove(int x, int y){
    object->frame->x2 = x;
    object->frame->y2 = y;
}
void LineSelection::Release(){

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
        return true;
    }
    else {
        return false;
    }
}
bool RectSelection::tryMove(int x, int y){
    object->frame->x2 = x-object->frame->x1;
    object->frame->y2 = y-object->frame->y1;
}
void RectSelection::Release(){

}


GroupSelection::GroupSelection(GrObject *obj){
    object = obj;
}
void GroupSelection::Draw(Painter *pntr){
//    qDebug() << object->frame->x1;
//    qDebug() << object->frame->y1;
//    qDebug() << object->frame->x2;
//    qDebug() << object->frame->y2;
    pntr->drawSelect(object->frame->x1,object->frame->y1);
    pntr->drawSelect(object->frame->x2,object->frame->y1);
    pntr->drawSelect(object->frame->x1,object->frame->y2);
    pntr->drawSelect(object->frame->x2,object->frame->y2);
}
bool GroupSelection::tryGrab(int x, int y){
    if ((x >= object->frame->x2-5 & x <= object->frame->x2+5) &(y >= object->frame->y2-5 & y <= object->frame->y2+5)){
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
