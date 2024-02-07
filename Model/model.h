#ifndef MODEL_H
#define MODEL_H

#include "scene.h"
#include "factory.h"
#include "objectstore.h"
#include "painter.h"
#include "paintcontroller.h"
#include "Selection/selectiondealler.h"
#include "Selection/selectionstore.h"
#include "groupdealler.h"
#include "Change/changedealler.h"
#include "Change/changestore.h"

class IModel{
public:
    virtual IFactory* getFactory() = 0;
    virtual IPaintController* getPaintController() = 0;
    virtual ISelectionDealler* getSelectionDealler() = 0;
    virtual ChangeDealler* getChangeDealler() = 0;

};


class Model : public IModel
{
public:
    Model();
//    void testDraw();
    IFactory* getFactory() override;
    IPaintController* getPaintController() override;
    ISelectionDealler* getSelectionDealler() override;
    ChangeDealler* getChangeDealler() override;

private:
    Scene *scene;
    IFactory *factory;
    ObjectStore *objectStore;
    IPaintController *paintController;
    ISelectionDealler *selectionDealler;
    SelectionStore *selectionStore;
    Painter *painter;
    GroupDealler *grDealler;
    ChangeDealler *changeDealler;
    ChangeStore *changeStore;

};

#endif // MODEL_H
