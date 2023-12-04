#ifndef STATE_H
#define STATE_H

#include "action.h"


class State
{
public:
    State(IAction *newAction);
    virtual void MouseMove (int x, int y) = 0;
    virtual void MouseUp (int x, int y) = 0;
    virtual void MouseDown (int x, int y) = 0;
protected:
    IAction *action;
};



class DragState : public State
{
public:
    DragState(IAction *newAction);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y) override;
    void MouseDown (int x, int y) override;
};

class CreateState : public State
{
public:
    CreateState(IAction *newAction);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y) override;
    void MouseDown (int x, int y) override;
};

#endif // STATE_H
