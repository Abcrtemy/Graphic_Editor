#ifndef STATE_H
#define STATE_H

#include "../Model/model.h"
#include "../Model/factory.h"
#include "../Model/Selection/selectiondealler.h"
#include <QObject>
#include <iostream>


class State
{
//    Q_OBJECT
public:
    State(IModel *nModel);
    virtual void MouseMove (int x, int y) = 0;
    virtual void MouseUp (int x, int y, std::function<void()> callback) = 0;
    virtual void MouseDown (int x, int y, std::function<void()> callback) = 0;
//signals:
//    virtual void changeToCreate();
//    virtual void changeToDrag();
protected:
    IFactory *factory;
    ISelectionDealler *dealler;
};



class DragState : public State
{
public:
    DragState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;
};

class CreateState : public State
{
public:
    CreateState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;
};

class EmptyState : public State
{
public:
    EmptyState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;

};
class SingleState : public State
{
public:
    SingleState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;

};
class MultiState : public State
{
public:
    MultiState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;

};
#endif // STATE_H
