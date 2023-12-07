#ifndef STATE_H
#define STATE_H

#include "../Model/model.h"
#include "../Model/factory.h"
#include "../Model/Selection/selectiondealler.h"


class State
{
public:
    State(IModel *nModel);
    virtual void MouseMove (int x, int y) = 0;
    virtual void MouseUp (int x, int y) = 0;
    virtual void MouseDown (int x, int y) = 0;
protected:
    IFactory *factory;
    ISelectionDealler *dealler;
};



class DragState : public State
{
public:
    DragState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y) override;
    void MouseDown (int x, int y) override;
};

class CreateState : public State
{
public:
    CreateState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y) override;
    void MouseDown (int x, int y) override;
};

#endif // STATE_H
