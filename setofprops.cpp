#include "setofprops.h"


//SetOfProps::SetOfProps()
//{

//}
void LineSetOfProps::changeLineProps(QColor newColor, int newWith, Qt::PenStyle newStyle){
    color = newColor;
    with = newWith;
    style = newStyle;
//    this->setRgb(newColor.red(), newColor.green(), newColor.blue());
//    qDebug() << color;
}
void LineSetOfProps::changeFillProps(QColor newColor){
//    fillColor = newColor;
    qDebug() << "LineFill Not Posible";
    return;
}



void FillSetOfProps::changeFillProps(QColor newColor){
    fillColor = newColor;
//    this->setRgb(newColor.red(), newColor.green(), newColor.blue());
//    qDebug() << fillColor;
}
void FillSetOfProps::changeLineProps(QColor newColor, int newWith, Qt::PenStyle style){
    qDebug() << "FillLine Not Posible";
    return;
}
