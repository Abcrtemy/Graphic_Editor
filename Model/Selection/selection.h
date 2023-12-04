#ifndef SELECTION_H
#define SELECTION_H
#include "../painter.h"
#include "../grobject.h"

class Selection
{
public:
    Selection();
    virtual void Draw(Painter *pntr) = 0;
    virtual bool tryGrab(int x, int y) = 0;
    virtual bool tryMove(int x, int y) = 0;
    virtual void Release() = 0;
protected:
    GrObject *object;
};



class LineSelection : public Selection
{
public:
    LineSelection(GrObject *obj);
    void Draw(Painter *pntr) override;
    bool tryGrab(int x, int y) override;
    bool tryMove(int x, int y) override;
    void Release() override;
};


class RectSelection : public Selection
{
public:
    RectSelection(GrObject *obj);
    void Draw(Painter *pntr) override;
    bool tryGrab(int x, int y) override;
    bool tryMove(int x, int y) override;
    void Release() override;
};

#endif // SELECTION_H
