#ifndef SELECTIONDEALLER_H
#define SELECTIONDEALLER_H

#include "selectionstore.h"
#include "../grobject.h"
#include "../figure.h"
#include "../objectstore.h"
#include "selection.h"


class ISelectionDealler
{
public:
    virtual void SelectAndGrab(GrObject *object, int x, int y) = 0;
    virtual void tryMoove(int x, int y) = 0;
    virtual void Release() = 0;
};


class SelectionDealler : public ISelectionDealler
{
public:
    SelectionDealler(SelectionStore *store, ObjectStore *objStore);
    void SelectAndGrab(GrObject *object, int x, int y) override;
    void tryMoove(int x, int y) override;
    void Release() override;
private:
    SelectionStore *selectionStore;
    ObjectStore *objectStore;
};

#endif // SELECTIONDEALLER_H