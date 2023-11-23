#include "figure.h"


Figure::Figure(Frame * frame1, PropList *newProps): GrObject(frame1){

}

void Figure::draw(Painter* painter){
    drawGeometry(painter);
}
void Figure::changeProps(SetOfProps * propsSet, Painter *painter){

}
Line::Line(Frame *frame1, PropList *newProps):Figure(frame1, newProps) {
    props = newProps;
    frame = frame1;
}

void Line::drawGeometry(Painter* painter) {
//    painter->changeLineProps(props);
    painter->drawLine(frame->x1,frame->y1,frame->x2,frame->y2);
}

void Line::changeProps(SetOfProps * propsSet, Painter *painter){
    props->addSet(propsSet,painter);
}


Rectangle::Rectangle(Frame *frame1, PropList *newProps): Figure(frame1,newProps){
    props = newProps;
    frame = frame1;
}

void Rectangle::drawGeometry(Painter* painter) {
//    painter->changeRectProps(props);
    painter->drawRectangle(frame->x1,frame->y1,frame->x2,frame->y2);
}

void Rectangle::changeProps(SetOfProps * propsSet, Painter *painter){
    props->addSet(propsSet,painter);
}
