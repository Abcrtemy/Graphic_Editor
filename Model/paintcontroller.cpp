#include "paintcontroller.h"

PaintController::PaintController(Scene *newScene, Painter *newPainter)
{
    scene = newScene;
    painter = newPainter;
}
void PaintController::SetPort(QGraphicsScene *port){
    painter->setPort(port);
}


void PaintController::Refresh(){

    scene->repaint();
}
