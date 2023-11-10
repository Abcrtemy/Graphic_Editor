#ifndef SETOFPROPS_H
#define SETOFPROPS_H

#include <qdebug.h>
#include <QColor>


class SetOfProps /*: public QColor*/
{
public:
//    virtual void changeLineProps(QColor newColor, int newWith, Qt::PenStyle newStyle) = 0;
//    virtual void changeFillProps(QColor newColor) = 0;
    virtual ~SetOfProps() = default;
};

class LineSetOfProps : public SetOfProps
{
public:
    LineSetOfProps(QColor newColor, Qt::PenStyle newStyle, int newWith);
    QColor color;
    Qt::PenStyle style;
    int with;
//    void changeLineProps(QColor newColor,int newWith, Qt::PenStyle newStyle) override;
//    void changeFillProps(QColor newColor) override;
private:
};

class FillSetOfProps : public SetOfProps
{
public:
    FillSetOfProps(QColor newFillColor);
    QColor fillColor;
//    void changeFillProps(QColor newColor) override;
//    void changeLineProps(QColor newColor, int newWith, Qt::PenStyle newStyle) override;
private:
};




#endif // SETOFPROPS_H
