#ifndef MODEL_H
#define MODEL_H

#include "scene.h"
#include "factory.h"
#include "objectstore.h"
#include "painter.h"
#include "paintcontroller.h"

class IModel{
public:
    virtual IFactory* getFactory() = 0;
    virtual IPaintController* getPaintController() = 0;
};


class Model : public IModel
{
public:
    Model();
//    void testDraw();
    IFactory* getFactory() override;
    IPaintController* getPaintController() override;

private:
    Scene *scene;
    IFactory *factory;
    ObjectStore *objectStore;
    IPaintController *paintController;
    Painter *painter;
};

#endif // MODEL_H
