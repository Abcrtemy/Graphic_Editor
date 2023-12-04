#include "graphicsscene.h"

GraphicsScene::GraphicsScene()
{
//    this->mouseReleaseEvent()
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
    //        QPointF *point = new QPointF();
    //        *point = event->pos();
    //        int x = point->x();
    //        int y = point->y();
        emit leftButtonReleased(event->scenePos().x(), event->scenePos().y());
    }
}

    void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton)
//    {
//        //        QPointF *point = new QPointF();
//        //        *point = event->pos();
//        //        int x = point->x();
//        //        int y = point->y();

//    }
    emit MsMoved(event->scenePos().x(), event->scenePos().y());
}

    void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if (event->button() == Qt::LeftButton)
    {
        //        QPointF *point = new QPointF();
        //        *point = event->pos();
        //        int x = point->x();
        //        int y = point->y();
        emit leftButtonPressed(event->scenePos().x(), event->scenePos().y());
    }

}
