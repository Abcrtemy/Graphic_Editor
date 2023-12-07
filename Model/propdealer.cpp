#include "propdealer.h"

PropDealer::PropDealer(IFactory *nFactory)
{
    factory = nFactory;
}

void PropDealer::changeProps(int width, int index, QColor lineColor, QColor fillColor){

//    lineProps = factory->getLineProps();
//    fillProps = factory->getFillProps();
    FillSetOfProps *fillProps = new FillSetOfProps(Qt::black);
    LineSetOfProps *lineProps = new LineSetOfProps(Qt::blue, Qt::DotLine, 3);
    lineProps->color = lineColor;
//    lineProps->style = lineStyle;
    lineProps->with = width;
    fillProps->fillColor = fillColor;
    factory->setFillProps(fillProps);
    factory->setLineProps(lineProps);
    if (index ==0){
        lineProps->style = Qt::SolidLine;
    }
    else if(index == 1){
        lineProps->style = Qt::DotLine;
    }
    else {
        lineProps->style = Qt::DashLine;
    }
}
