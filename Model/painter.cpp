#include "painter.h"
#include "qdebug.h"

Painter::Painter()
{
//    shapes = new QGraphicsItemGroup();
    pen = *new QPen();
    brush = *new QBrush();
}
void Painter::setPort(QGraphicsScene *newScene){
        scene = newScene;
    pen.setColor(Qt::white);
}
//void Painter::changeLineProps(PropList* props){
//    pen.setColor(QColorConstants::Black);
//    pen.setWidth(2);
//    pen.setStyle(Qt::SolidLine);
//    pen.setBrush(Qt::black);
//    if (props->empty() == false){
//        for (int i = props->length(); i >= 0; i--) {
//            if (dynamic_cast<LineSetOfProps*>(props->value(i))){
//                SetOfProps* SetPropsl = props->value(i);
//                LineSetOfProps* lineProps = dynamic_cast<LineSetOfProps*>(SetPropsl);
//                pen.setColor(lineProps->color);
//                pen.setWidth(lineProps->with);
//                pen.setStyle(lineProps->style);
//                break;
//            }
//        }
//        for (int j = props->length(); j >= 0; j--) {
//            if (dynamic_cast<FillSetOfProps*>(props->value(j))){
//                SetOfProps* SetPropsf = props->value(j);
//                FillSetOfProps* fillProps = dynamic_cast<FillSetOfProps*>(SetPropsf);
//                pen.setColor(fillProps->fillColor);
//                break;
//            }
//        }

//    }
//    else {
////        pen.setColor(QColorConstants::Black);
////        pen.setWidth(2);
////        pen.setStyle(Qt::SolidLine);
//    }
//}

void Painter::drawLine(int x1, int y1, int x2, int y2){
//    QPen penBlack(Qt::black);
//    shapes->addToGroup(addLine(0, 0, 20, 20, penBlack));
    scene->addLine(x1, y1, x2, y2, pen);
//    scene->addLine(20,20,width() - 20, 20, penBlack);
}


void Painter::drawRectangle(int x1, int y1, int x2, int y2){
//    QPen penBlack(Qt::black);
//    qDebug() << brush.color();
    scene->addRect(x1, y1, x2, y2, pen,brush);

}

void Painter::drawSelect(int x, int y){
    QPen selPen = *new QPen();
    selPen.setColor(Qt::white);
    scene->addRect(x,y,6,6,selPen);
}


//void Painter::changeRectProps(PropList* props){
//    pen.setColor(QColorConstants::Black);
//    pen.setWidth(2);
//    pen.setStyle(Qt::SolidLine);
//    pen.setBrush(Qt::black);
//    if (props->empty() == false){
//        for (int i = props->length(); i >= 0; i--) {
//            if (dynamic_cast<LineSetOfProps*>(props->value(i))){
//                SetOfProps* SetPropsl = props->value(i);
//                LineSetOfProps* lineProps = dynamic_cast<LineSetOfProps*>(SetPropsl);
//                pen.setColor(lineProps->color);
//                pen.setWidth(lineProps->with);
//                pen.setStyle(lineProps->style);
//                break;
//            }
//        }
//        for (int j = props->length(); j >= 0; j--) {
//            if (dynamic_cast<FillSetOfProps*>(props->value(j))){
//                SetOfProps* SetPropsf = props->value(j);
//                FillSetOfProps* fillProps = dynamic_cast<FillSetOfProps*>(SetPropsf);
//                brush.setColor(fillProps->fillColor);
//                brush.setStyle(Qt::SolidPattern);

//                break;
//            }
//        }

//    }
//}
