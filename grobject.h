#ifndef GROBJECT_H
#define GROBJECT_H

#include "painter.h"
#include "frame.h"

class GrObject
{
public:
    GrObject(Frame *frame);
    virtual void draw(Painter* painter);
};

#endif // GROBJECT_H
