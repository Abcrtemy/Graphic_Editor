#ifndef SELECTIONSTORE_H
#define SELECTIONSTORE_H

#include <QList>
#include "selection.h"
#include "../painter.h"



class SelectionStore : public QList <Selection*>
{
public:
    SelectionStore();
    Selection *activeSelection;
    void tryGrab(int x, int y);
    bool tryMove();
    void Release();
    void draw (Painter *painter);
    QList<GrObject*> *getObjList();
private:
    QList<GrObject*> *list;
};

#endif // SELECTIONSTORE_H
