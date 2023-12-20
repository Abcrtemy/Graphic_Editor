#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>


class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene();
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
//    void esEvent(QGraphicsSceneMouseEvent *event) override;
signals:
    void leftButtonPressed(int x, int y);
    void leftButtonReleased(int x, int y);
    void MsMoved(int x, int y);
    void ShiftMsUp(int x, int y);
    void Del();
    void ESC();
protected:


};

#endif // GRAPHICSSCENE_H
