#include "scene.h"
#include <QDebug>
Scene::Scene(ObjectStore *newStore, Painter *newPainter)
{
    store = newStore;
    painter = newPainter;
}

void Scene::repaint(){
    for(int i = 0; i < store->length(); i ++){
        store->value(i)->draw(painter);
        qDebug() << i;
    }
}

