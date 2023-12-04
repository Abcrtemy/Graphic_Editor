#ifndef STATESTORE_H
#define STATESTORE_H

#include <QList>
#include "createstate.h"
#include "dragstate.h"

class StateStore : public QList<State*>
{
public:
    StateStore();
private:
    State *dragState;
    State *createState;
};

#endif // STATESTORE_H
