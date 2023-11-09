#include "figure.h"



void Figure::draw(Painter* painter){

}
void Figure::changeLine(QColor newColor, int with, Qt::PenStyle style){

}
void Figure::changeFill(QColor newColor){

}
Line::Line(int x1, int y1, int x2, int y2){
    props = new PropList;
    frame = new Frame(x1,y1,x2,y2);
}

void Line::draw(Painter* painter) {
    painter->changeLineProps(props);
    painter->drawLine(frame->x1,frame->y1,frame->x2,frame->y2);
}

void Line::changeLine(QColor newColor, int with, Qt::PenStyle style){
    props->changeLinePropsSet(newColor, with, style);
}
void Line::changeFill(QColor newColor){
    props->changeFillPropsSet(newColor);
}


Rectangle::Rectangle(int x1, int y1, int x2, int y2){
    props = new PropList;
    frame = new Frame(x1,y1,x2,y2);
}

void Rectangle::draw(Painter* painter) {
    painter->changeRectProps(props);
    painter->drawRectangle(frame->x1,frame->y1,frame->x2,frame->y2);
}

void Rectangle::changeFill(QColor newColor){
    props->changeFillPropsSet(newColor);
}
void Rectangle::changeLine(QColor newColor, int with, Qt::PenStyle style){
    props->changeLinePropsSet(newColor, with, style);
}





//Figure::Figure()
//{
////    props = new PropList();
//}


//    PropList <LineSetOfProps> *props = new PropList<LineSetOfProps>;
//void Figure::draw(QObject painter, int x1, int x2, int y1, int y2){

//}




//QObject Frame, QObject PropList
