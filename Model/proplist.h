#ifndef PROPLIST_H
#define PROPLIST_H

#include <QList>
#include <QVector>
#include <QPair>
#include <QColor>
#include "painter.h"
#include "setofprops.h"

//template <class T>
class PropList : public QVector <SetOfProps*>
{
public:
    PropList();
//    void changeLinePropsSet(QColor newLineColor, int with, Qt::PenStyle style);
//    void changeFillPropsSet(QColor newFillColor);
    void addSet(SetOfProps *propset);
    void applySets(Painter *painter);
private:
//    SetOfProps* linePropsSet;
//    SetOfProps* fillPropsSet;
};

#endif // PROPLIST_H
