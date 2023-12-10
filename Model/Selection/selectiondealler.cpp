#include "selectiondealler.h"

SelectionDealler::SelectionDealler(SelectionStore *store, ObjectStore *objStore)
{
    selectionStore = store;
    objectStore = objStore;
}

void SelectionDealler::SelectCreated( int x, int y){
    for (int i = 0; i <= objectStore->length(); i++){
        if (objectStore->value(i)->frame->x1 == x & objectStore->value(i)->frame->y1 == y){
            if (dynamic_cast<Rectangle*>(objectStore->value(i))){
                Selection *selection = new RectSelection(objectStore->value(i));
                selectionStore->append(selection);
                selectionStore->tryGrab(x, y);
                break;
            }
            if (dynamic_cast<Line*>(objectStore->value(i))){
                Selection *selection = new LineSelection(objectStore->value(i));
                selectionStore->append(selection);
                selectionStore->tryGrab(x, y);
                break;
            }
        }
    }



//    if (dynamic_cast<Rectangle*>(object)){
//        Selection *selection = new RectSelection(object);
//        selectionStore->append(selection);
//        selectionStore->tryGrab(x, y);
//    }
//    if (dynamic_cast<Line*>(object)){
//        Selection *selection = new LineSelection(object);
//        selectionStore->append(selection);
//        selectionStore->tryGrab(x, y);
//    }
}
//void SelectionDealler::trySelect(int x, int y){
//    if (selectionStore->activeSelection != NULL){
//        selectionStore->activeSelection->tryMove(x,y);
//    }
//}
void SelectionDealler::tryMoove(int x, int y){
    if (selectionStore->activeSelection != NULL){
        selectionStore->activeSelection->tryMove(x,y);
    }
}

void SelectionDealler::Release(){
    selectionStore->Release();
}

void SelectionDealler::Draw(Painter* painter){
    selectionStore->draw(painter);
}
