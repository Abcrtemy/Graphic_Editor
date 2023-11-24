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
signals:
    void leftButtonPressed(int x, int y);
protected:


};

#endif // GRAPHICSSCENE_H
