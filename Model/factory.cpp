#include "factory.h"
#include <QColor>

Factory::Factory(ObjectStore *newStore)
{
    store = newStore;
}

void Factory::createItem(int x, int y){
    PropList *propList = new PropList();
    if (createObjectType == LineType){
        Frame *frame = new Frame(x,y,x+100,y+100);
        Figure *figure = new Line(frame, propList);
//        SetOfProps *lineProps = new LineSetOfProps(Qt::white, Qt::SolidLine, 2);
//        figure->changeProps(lineProps,)
        store->append(figure);
    }
    else {
        Frame *frame = new Frame(x,y,100,100);
        Figure* figure = new Rectangle(frame, propList);
        store->append(figure);
    }
//    Frame *frame = new Frame(x,y,x+100,y+100);
//    Figure* figure = new Line(frame, propList);


}

void Factory::setType(CreateObjectType objectType){
    createObjectType = objectType;
}

CreateObjectType Factory::getType(){
    return createObjectType;
}
