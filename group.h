#ifndef GROUP_H
#define GROUP_H

#include <QVector>
#include "figure.h"
#include "painter.h"
#include "grobject.h"


class Group : public GrObject
{
public:
//    Group();
    void addToGroup(GrObject *obj);
    void draw(Painter * painter);
    QList <GrObject *> *gr;
private:
    QVector <Figure*> *group;
};

#endif // GROUP_H
