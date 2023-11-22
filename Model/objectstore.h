#ifndef OBJECTSTORE_H
#define OBJECTSTORE_H

#include "grobject.h"


class ObjectStore : public QList<GrObject*>
{
public:
    ObjectStore();
};

#endif // OBJECTSTORE_H
