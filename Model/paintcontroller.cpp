#include "paintcontroller.h"

PaintController::PaintController(Scene *newScene, Painter *newPainter)
{
    scene = newScene;
    painter = newPainter;
}
void PaintController::SetPort(QGraphicsScene *nport){
    port = nport;
    painter->setPort(nport);
}


void PaintController::Refresh(){
//    port->clear();
    scene->repaint();
}
