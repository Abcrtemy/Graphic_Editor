#include "figure.h"


Figure::Figure(Frame * frame1, PropList *newProps): GrObject(frame1){

}

void Figure::draw(Painter* painter){
    drawGeometry(painter);
}
void Figure::changeProps(SetOfProps * propsSet){

}
Line::Line(Frame *frame1, PropList *newProps):Figure(frame1, newProps) {
    props = newProps;
    frame = frame1;
}

void Line::drawGeometry(Painter* painter) {
//    painter->changeLineProps(props);
    props->applySets(painter);
    painter->drawLine(frame->x1,frame->y1,frame->x2,frame->y2);
}

void Line::changeProps(SetOfProps * propsSet){
    props->addSet(propsSet);
}


Rectangle::Rectangle(Frame *frame1, PropList *newProps): Figure(frame1,newProps){
    props = newProps;
    frame = frame1;
}

void Rectangle::drawGeometry(Painter* painter) {
//    painter->changeRectProps(props);
    props->applySets(painter);
    painter->drawRectangle(frame->x1,frame->y1,frame->x2,frame->y2);
}

void Rectangle::changeProps(SetOfProps * propsSet){
//    props->applySets(painter);
    props->addSet(propsSet);
}
