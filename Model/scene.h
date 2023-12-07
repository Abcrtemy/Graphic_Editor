#ifndef SCENE_H
#define SCENE_H

#include "objectstore.h"
#include "painter.h"
#include "Selection/selectiondealler.h"

class Scene
{
public:
    Scene(ObjectStore *newStore, Painter *newPainter, ISelectionDealler *nDealler);
    void repaint();
private:
    ObjectStore *store;
    Painter *painter;
    ISelectionDealler *dealler;
};

#endif // SCENE_H
