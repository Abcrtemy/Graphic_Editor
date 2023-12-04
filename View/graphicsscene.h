#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>


class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void leftButtonPressed(int x, int y);
    void leftButtonReleased(int x, int y);
    void MsMoved(int x, int y);
//    void leftButton(int x, int y);
//    void leftButtonPressed(int x, int y);
protected:


};

#endif // GRAPHICSSCENE_H
