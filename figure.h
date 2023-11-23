#ifndef FIGURE_H
#define FIGURE_H

#include "painter.h"
#include "proplist.h"
#include "setofprops.h"
#include "frame.h"
#include "grobject.h"

#include <QColor>


//#include <QObject>
#include <QGraphicsScene>
class Figure : public GrObject
{
public:
    Figure(Frame *frame, PropList *newProps);
    void draw(Painter* painter) override;
    virtual void changeProps(SetOfProps * propsSet, Painter *painter);
protected:
    PropList *props;
    virtual void drawGeometry(Painter *painter) = 0;
};



class Line : public Figure
{
public:
    Line(Frame *frame1, PropList *newProps);
    void drawGeometry(Painter* painter) override;
    void changeProps(SetOfProps * propsSet, Painter *painter) override;
};




class Rectangle : public Figure
{
public:
    Rectangle(Frame *frame1, PropList *newProps);
    void drawGeometry(Painter* painter) override;
    void changeProps(SetOfProps * propsSet, Painter *painter) override;
};






//class Figure
//{
//public:
//    Figure();
//    void draw(QObject painter);
//};



#endif // FIGURE_H
