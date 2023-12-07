#include "factory.h"
#include <QColor>

#include "math.h"
#include <cmath>

Factory::Factory(ObjectStore *newStore, ISelectionDealler *dealer)
{
    selectionDealer = dealer;
    store = newStore;
    fillProps = new FillSetOfProps(Qt::black);
    lineProps = new LineSetOfProps(Qt::white, Qt::SolidLine, 2);
}
void Factory::createAndGrabItem(int x, int y){
    PropList *propList = new PropList();
    if (createObjectType == LineType){
        Frame *frame = new Frame(x,y,x,y);
        Figure *figure = new Line(frame, propList);
//        SetOfProps *lineProp = new LineSetOfProps(Qt::blue, Qt::DotLine, 3);
//        lineProp = lineProps;
        figure->changeProps(lineProps);
        store->append(figure);
        selectionDealer->SelectAndGrab(figure,x,y);
    }
    else {
        Frame *frame = new Frame(x,y,0,0);
        Figure* figure = new Rectangle(frame, propList);
//        SetOfProps *lineProp = new LineSetOfProps(Qt::green, Qt::DashLine, 3);
//        SetOfProps *lineProp = new LineSetOfProps(Qt::blue, Qt::DotLine, 3);
//        lineProp = lineProps;
//        SetOfProps *fillProp = new FillSetOfProps(Qt::blue);
//        fillProp = *fillProps;
        figure->changeProps(fillProps);
        figure->changeProps(lineProps);
        store->append(figure);
        selectionDealer->SelectAndGrab(figure,x,y);
    }
}


void Factory::createItem(int x, int y){
    selectionDealer->Release();
\
}
void Factory::GrabItem(int x, int y){
    selectionDealer->tryMoove(x,y);
    \
}
void Factory::setType(CreateObjectType objectType){
    createObjectType = objectType;
}



CreateObjectType Factory::getType(){
    return createObjectType;
}


void Factory::setFillProps(FillSetOfProps* fprops){
    fillProps = fprops;
//    return fillProps;
}
void Factory::setLineProps(LineSetOfProps* lprops){
    lineProps = lprops;

}
