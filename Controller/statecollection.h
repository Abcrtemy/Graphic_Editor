#ifndef STATECOLLECTION_H
#define STATECOLLECTION_H


#include <QList>
#include "state.h"
#include "../Model/model.h"
//#include "action.h"
enum NowState {
    drState, crState
};
class StateCollection : public QList<State*>
{
public:
    StateCollection(IModel *model);
    void mouseUp(int x, int y);
    void mouseDown(int x, int y);
    void mouseMoove(int x, int y);
private:
    State *dragState;
    State *createState;
    NowState nowState;
};

#endif // STATECOLLECTION_H
