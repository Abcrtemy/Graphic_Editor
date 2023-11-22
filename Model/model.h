#ifndef MODEL_H
#define MODEL_H

#include "scene.h"
#include "factory.h"
#include "objectstore.h"
#include "painter.h"

class Model
{
public:
    Model();
    void testDraw();
private:
    Scene *scene;
    Factory *factory;
    ObjectStore *objectStore;
    Painter *painter;
};

#endif // MODEL_H
