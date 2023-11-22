#ifndef SCENE_H
#define SCENE_H

#include "objectstore.h"
#include "painter.h"

class Scene
{
public:
    Scene(ObjectStore *newStore, Painter *newPainter);
    void repaint();
private:
    ObjectStore *store;
    Painter *painter;
};

#endif // SCENE_H
