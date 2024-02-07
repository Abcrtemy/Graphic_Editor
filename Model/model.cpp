#include "model.h"

Model::Model()
{


    objectStore = new ObjectStore;
    selectionStore = new SelectionStore();
    grDealler = new GroupDealler(objectStore, selectionStore);
    changeStore = new ChangeStore();
    changeDealler = new ChangeDealler(changeStore, objectStore, grDealler);
    selectionDealler = new SelectionDealler(selectionStore, objectStore, grDealler, changeDealler);

    factory = new Factory(objectStore, selectionDealler);
    painter = new Painter();
    scene = new Scene(objectStore, painter,selectionDealler);
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

ChangeDealler* Model::getChangeDealler(){
    return changeDealler;
}

ISelectionDealler* Model::getSelectionDealler(){
    return selectionDealler;
}
IPaintController* Model::getPaintController(){
    return paintController;
}
