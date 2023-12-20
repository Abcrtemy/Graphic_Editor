#ifndef GROUP_H
#define GROUP_H

#include <QVector>
#include "figure.h"
#include "painter.h"
#include "grobject.h"


class Group : public GrObject
{
public:
    Group(Frame *frame1);
    void addToGroup(GrObject *obj);
    void draw(Painter * painter) override;
    bool inBody(int x, int y) override;
    QList <GrObject *> *gr;
    void refactorCoordinats(int a, int b);
    float countK(int x, int max, int min);
private:
    QVector <Figure*> *group;
};

#endif // GROUP_H
