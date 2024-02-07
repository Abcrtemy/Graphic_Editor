#ifndef SELECTIONDEALLER_H
#define SELECTIONDEALLER_H

#include "selectionstore.h"
#include "../grobject.h"
#include "../figure.h"
#include "../objectstore.h"
#include "selection.h"
#include "../groupdealler.h"
#include "../Change/changedealler.h"


class ISelectionDealler
{
public:
    virtual void SelectCreated( int x, int y) = 0;
    virtual void tryMoove(int x, int y) = 0;
    virtual void mooveFigure(int x, int y) = 0;
    virtual bool trySelect(int x, int y) = 0;
    virtual bool addSelection(int x, int y) = 0;
    virtual void Release() = 0;
    virtual void Draw(Painter *painter) = 0;
    virtual bool tryGrab(int x, int y) = 0;
    virtual void del() = 0;
    virtual void group() = 0;
    virtual void unGroup() = 0;
    virtual void rememberCoordinats() = 0;
    int globalX;
    int globalY;
protected:
    QList<GrObject*> *list;
    ChangeDealler *changeDealler;


};


class SelectionDealler : public ISelectionDealler
{
public:
    SelectionDealler(SelectionStore *store, ObjectStore *objStore, GroupDealler *grDealler, ChangeDealler *chDealler);
    void SelectCreated(int x, int y) override;
    void tryMoove(int x, int y) override;
    bool trySelect(int x, int y) override;
    bool addSelection(int x, int y) override;
    void Release() override;
    void Draw(Painter *painter) override;
    bool tryGrab(int x, int y) override;
    void del() override;
    void group() override;
    void unGroup() override;
    void mooveFigure(int x, int y) override;
    void rememberCoordinats() override;
private:
    SelectionStore *selectionStore;
    ObjectStore *objectStore;
    GroupDealler *groupDealler;

};

#endif // SELECTIONDEALLER_H
