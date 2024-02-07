#ifndef CHANGESTORE_H
#define CHANGESTORE_H

#include "change.h"
#include <QList>

class ChangeStore : public QList <Change*>
{
public:
    ChangeStore();

};

#endif // CHANGESTORE_H
