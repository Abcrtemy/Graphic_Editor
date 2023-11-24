#include "model.h"

Model::Model()
{


    objectStore = new ObjectStore;
    factory = new Factory(objectStore);
    painter = new Painter();
    scene = new Scene(objectStore, painter);
    paintController = new PaintController(scene, painter);
//    paintController->SetPort(port);
//    testDraw();
    paintController->Refresh();
}

//void Model::testDraw(){
////    factory->createItem();
////    factory->createItem();
////    scene->repaint();
//}

IFactory* Model::getFactory(){
    return factory;
}
IPaintController* Model::getPaintController(){
    return paintController;
}
