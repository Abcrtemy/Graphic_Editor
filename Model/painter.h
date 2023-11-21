#ifndef PAINTER_H
#define PAINTER_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
//#include "setofprops.h"
//#include "proplist.h"


class Painter
{
//    Q_OBJECT
public:
    Painter(QGraphicsScene *newScene);

    void drawLine(int x1, int y1, int x2, int y2);
    void drawRectangle(int x1, int y1, int x2, int y2);
//    void changeLineProps(PropList* props);
//    void changeRectProps(PropList* props);
    QPen pen;
    QBrush brush;
private:
    QGraphicsItemGroup *shapes;
    QGraphicsScene *scene;
//    QPen pen;
//    QBrush brush;
};

#endif // PAINTER_H
