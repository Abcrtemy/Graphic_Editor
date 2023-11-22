#include "factory.h"

Factory::Factory(ObjectStore *newStore)
{
    store = newStore;
}

void Factory::createItem(){
    PropList *propList = new PropList();
    Frame *frame = new Frame(0,100,-100,200);
    Figure* line = new Line(frame, propList);
    store->append(line);

}
