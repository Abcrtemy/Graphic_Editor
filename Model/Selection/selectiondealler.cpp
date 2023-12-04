#include "selectiondealler.h"

SelectionDealler::SelectionDealler(SelectionStore *store, ObjectStore *objStore)
{
    selectionStore = store;
    objectStore = objStore;
}

void SelectionDealler::SelectAndGrab(GrObject *object, int x, int y){
    if (dynamic_cast<Rectangle*>(object)){
        Selection *selection = new RectSelection(object);
        selectionStore->append(selection);
        selectionStore->tryGrab(x, y);
    }
    if (dynamic_cast<Line*>(object)){
        Selection *selection = new LineSelection(object);
        selectionStore->append(selection);
        selectionStore->tryGrab(x, y);
    }
}

void SelectionDealler::tryMoove(int x, int y){
    if (selectionStore->activeSelection != NULL){
        selectionStore->activeSelection->tryMove(x,y);
    }
}

void SelectionDealler::Release(){
    selectionStore->Release();
}
