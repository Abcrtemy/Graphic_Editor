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
//public slots:
    void changetoCreate();
    void changeToDrag();
private:
    State *dragState;
    State *createState;
    State *nowState;
};

#endif // STATECOLLECTION_H
