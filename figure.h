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
//    Figure();
    virtual void draw(Painter* painter);
    virtual void changeProps(SetOfProps * propsSet, Painter *painter);
//    virtual void changeFill(QColor newColor);
//    virtual void Line();
//    virtual void Rectangle();
//    PropList <LineSetOfProps> *props;

//    virtual void drawRectangle(Painter* painter, int x1, int y1, int x2, int y2) = 0 ;
private:
//    PropList* props;
//    PropList* props;
};



class Line : public Figure
{
public:
    Line(int x1, int y1, int x2, int y2);
    void draw(Painter* painter) override;
    void changeProps(SetOfProps * propsSet, Painter *painter) override;
//    void changeFill(QColor newColor) override;
private:
    PropList *props;
    Frame *frame;
//        override;
};




class Rectangle : public Figure
{
public:
    Rectangle(int x1, int y1, int x2, int y2);
    void draw(Painter* painter) override;
    void changeProps(SetOfProps * propsSet, Painter *painter) override;
//    void changeFill(QColor newColor) override;
private:
    PropList *props;
    Frame *frame;
};






//class Figure
//{
//public:
//    Figure();
//    void draw(QObject painter);
//};



#endif // FIGURE_H
