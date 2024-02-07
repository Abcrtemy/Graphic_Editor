#ifndef STATE_H
#define STATE_H

#include "../Model/model.h"
#include "../Model/factory.h"
#include "../Model/Selection/selectiondealler.h"
#include <QObject>
#include <iostream>
#include "../Model/Change/changedealler.h"


class State
{
//    Q_OBJECT
public:
    State(IModel *nModel);
    virtual void MouseMove (int x, int y) = 0;
    virtual void MouseUp (int x, int y, std::function<void()> drag, std::function<void()> empty, std::function<void()> single) = 0;
    virtual void MouseDown (int x, int y, std::function<void()> callback) = 0;
    virtual void ShiftMouseUp(int x, int y, std::function<void()> multi) = 0;
    virtual void esc(std::function<void()> empty) = 0;
    virtual void del(std::function<void()> empty) = 0;
    virtual void group(std::function<void()> single) = 0;
    virtual void unGroup(std::function<void()> multi) = 0;
    virtual void undo(std::function<void()> empty) = 0;
    virtual void redo(std::function<void()> empty) = 0;
protected:
    IFactory *factory;
    ISelectionDealler *dealler;
    ChangeDealler *changeDealler;
};



class DragState : public State
{
public:
    DragState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback, std::function<void()> empty, std::function<void()> single) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;
    void ShiftMouseUp(int x, int y, std::function<void()> multi) override;
    void esc(std::function<void()> empty) override;
    void del(std::function<void()> empty) override;
    void group(std::function<void()> single) override;
    void unGroup(std::function<void()> multi) override;
    void undo(std::function<void()> empty) override;
    void redo(std::function<void()> empty) override;
};

class CreateState : public State
{
public:
    CreateState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback, std::function<void()> empty, std::function<void()> single) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;
    void ShiftMouseUp(int x, int y, std::function<void()> multi) override;
    void esc(std::function<void()> empty) override;
    void del(std::function<void()> empty) override;
    void group(std::function<void()> single) override;
    void unGroup(std::function<void()> multi) override;
    void undo(std::function<void()> empty) override;
    void redo(std::function<void()> empty) override;
};

class EmptyState : public State
{
public:
    EmptyState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback, std::function<void()> empty, std::function<void()> single) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;
    void ShiftMouseUp(int x, int y, std::function<void()> multi) override;
    void esc(std::function<void()> empty) override;
    void del(std::function<void()> empty) override;
    void group(std::function<void()> single) override;
    void unGroup(std::function<void()> multi) override;
    void undo(std::function<void()> empty) override;
    void redo(std::function<void()> empty) override;

};
class SingleState : public State
{
public:
    SingleState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback, std::function<void()> empty, std::function<void()> single) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;
    void ShiftMouseUp(int x, int y, std::function<void()> multi) override;
    void esc(std::function<void()> empty) override;
    void del(std::function<void()> empty) override;
    void group(std::function<void()> single) override;
    void unGroup(std::function<void()> multi) override;
    void undo(std::function<void()> empty) override;
    void redo(std::function<void()> empty) override;
    int amountOfMoovments = 0;
};
class MultiState : public State
{
public:
    MultiState(IModel *nModel);
    void MouseMove (int x, int y) override;
    void MouseUp (int x, int y, std::function<void()> callback, std::function<void()> empty, std::function<void()> single) override;
    void MouseDown (int x, int y, std::function<void()> callback) override;
    void ShiftMouseUp(int x, int y, std::function<void()> multi) override;
    void esc(std::function<void()> empty) override;
    void del(std::function<void()> empty) override;
    void group(std::function<void()> single) override;
    void unGroup(std::function<void()> multi) override;
    void undo(std::function<void()> empty) override;
    void redo(std::function<void()> empty) override;
};
#endif // STATE_H
