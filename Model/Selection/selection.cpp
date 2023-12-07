#include "selection.h"

Selection::Selection()
{

}
LineSelection::LineSelection(GrObject *obj){
    object = obj;

}
void LineSelection::Draw(Painter *pntr){
    pntr->drawSelect(object->frame->x1,object->frame->y1);
//    pntr->drawSelect(object->frame->x2,object->frame->y1);
//    pntr->drawSelect(object->frame->x1,object->frame->y2);
    pntr->drawSelect(object->frame->x2,object->frame->y2);
}
bool LineSelection::tryGrab(int x, int y){
    if (object->inBody(x,y) == true){
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
    if (object->inBody(x,y) == true){
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
