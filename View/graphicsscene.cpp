#include "graphicsscene.h"

GraphicsScene::GraphicsScene()
{

}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
//        if (event->modifiers()   )
        if ( event->modifiers() == Qt::ShiftModifier)
        {
            emit ShiftMsUp(event->scenePos().x(), event->scenePos().y());
            return;
        }
        emit leftButtonReleased(event->scenePos().x(), event->scenePos().y());
    }
}
void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    emit MsMoved(event->scenePos().x(), event->scenePos().y());
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        emit leftButtonPressed(event->scenePos().x(), event->scenePos().y());
    }
}

void GraphicsScene::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_X)
    {
        emit Del();
    }
    if (event->key() == Qt::Key_Escape)
    {
        emit ESC();
    }

}
