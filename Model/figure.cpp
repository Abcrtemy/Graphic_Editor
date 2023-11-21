#include "figure.h"


Figure::Figure(Frame * frame1): GrObject(frame1){

}

void Figure::draw(Painter* painter){

}
void Figure::changeProps(SetOfProps * propsSet, Painter *painter){

}
//void Figure::changeFill(QColor newColor){

//}
Line::Line(Frame *frame1, PropList *newProps):Figure(frame1) {
    props = newProps;
    frame = frame1;
}

void Line::draw(Painter* painter) {
//    painter->changeLineProps(props);
    painter->drawLine(frame->x1,frame->y1,frame->x2,frame->y2);
}

void Line::changeProps(SetOfProps * propsSet, Painter *painter){
    props->addSet(propsSet,painter);
}
//void Line::changeFill(QColor newColor){
//    props->changeFillPropsSet(newColor);
//}


Rectangle::Rectangle(Frame *frame1, PropList *newProps): Figure(frame1){
    props = newProps;
    frame = frame1;
}

void Rectangle::draw(Painter* painter) {
//    painter->changeRectProps(props);
    painter->drawRectangle(frame->x1,frame->y1,frame->x2,frame->y2);
}

//void Rectangle::changeFill(QColor newColor){
//    props->changeFillPropsSet(newColor);
//}
void Rectangle::changeProps(SetOfProps * propsSet, Painter *painter){
    props->addSet(propsSet,painter);
}





//Figure::Figure()
//{
////    props = new PropList();
//}


//    PropList <LineSetOfProps> *props = new PropList<LineSetOfProps>;
//void Figure::draw(QObject painter, int x1, int x2, int y1, int y2){

//}




//QObject Frame, QObject PropList
