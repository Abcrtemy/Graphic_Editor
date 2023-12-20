#ifndef STATECOLLECTION_H
#define STATECOLLECTION_H


#include <QList>
#include "state.h"
#include "../Model/model.h"
#include <QObject>
//#include "action.h"
//enum NowState {
//    drState, crState
//};
class StateCollection : public QList<State*>
{
//    Q_OBJECT
public:
    StateCollection(IModel *model);
    void mouseUp(int x, int y);
    void mouseDown(int x, int y);
    void mouseMoove(int x, int y);
    void shiftMouseUp(int x, int y);
    void esc();
    void del();
    void group();
    void unGroup();
    void startCreate();
private:
    State *dragState;
    State *createState;
    State *emptyState;
    State *multiState;
    State *singleState;
    State *nowState;
    void changetoCreate();
    void changeToDrag();
    void changeToEmpty();
    void changeToSingle();
    void changeToMulti();
};

#endif // STATECOLLECTION_H
