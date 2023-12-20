#ifndef PAINTCONTROLLER_H
#define PAINTCONTROLLER_H

#include <QGraphicsScene>
#include "scene.h"
#include "painter.h"

class IPaintController{
public:
    virtual void SetPort(QGraphicsScene *port) = 0;
    virtual void Refresh() = 0;
};


class PaintController : public IPaintController
{
public:
    PaintController(Scene *newScene, Painter *painter);
    void SetPort(QGraphicsScene *nport) override;
    void Refresh() override;
private:
    Scene *scene;
    Painter *painter;
    QGraphicsScene *port;
};

#endif // PAINTCONTROLLER_H
