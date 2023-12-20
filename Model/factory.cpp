#include "factory.h"
#include <QColor>

#include "math.h"
#include "group.h"
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
        figure->changeProps(lineProps);
        store->append(figure);
    }
    else {
        Frame *frame = new Frame(x,y,0,0);
        Figure* figure = new Rectangle(frame, propList);
        figure->changeProps(fillProps);
        figure->changeProps(lineProps);
        store->append(figure);
    }
}

void Factory::createGroup(){
    Frame *frame = new Frame(0,0,0,0);
    GrObject *group = new Group(frame);
    store->append(group);
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

