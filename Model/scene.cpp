#include "scene.h"
#include <QDebug>
Scene::Scene(ObjectStore *newStore, Painter *newPainter, ISelectionDealler *nDealler)
{
    store = newStore;
    painter = newPainter;
    dealler = nDealler;
}

void Scene::repaint(){
    for(int i = 0; i < store->length(); i ++){
        store->value(i)->draw(painter);
        qDebug() << i;
    }
    dealler->Draw(painter);
}

