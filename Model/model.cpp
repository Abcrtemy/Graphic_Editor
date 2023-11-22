#include "model.h"

Model::Model()
{


    objectStore = new ObjectStore;
    factory = new Factory(objectStore);
    painter = new Painter();
    scene = new Scene(objectStore, painter);
    testDraw();
}

void Model::testDraw(){
    factory->createItem();
    scene->repaint();
}
