#include "selectiondealler.h"

SelectionDealler::SelectionDealler(SelectionStore *store, ObjectStore *objStore, GroupDealler *grDealler)
{
    selectionStore = store;
    objectStore = objStore;
    list = store->getObjList();
    groupDealler = grDealler;
}

void SelectionDealler::SelectCreated( int x, int y){
    for (int i = objectStore->length()-1; i >=0; i--){
        if (objectStore->value(i)->frame->x1 == x & objectStore->value(i)->frame->y1 == y){
            selectionStore->Release();
            list->clear();
            if (dynamic_cast<Rectangle*>(objectStore->value(i))){
                Selection *selection = new RectSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->tryGrab(x, y);
                break;
            }
            else if (dynamic_cast<Line*>(objectStore->value(i))){
                Selection *selection = new LineSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->tryGrab(x, y);
                break;
            }
            else {
                Selection *selection = new GroupSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->tryGrab(x, y);
                break;
            }
        }
    }
}
bool SelectionDealler::trySelect(int x, int y){
    for (int i = objectStore->length()-1; i >= 0; i--){
        if (objectStore->value(i)->inBody(x,y) == true){
            selectionStore->Release();
            list->clear();
            if (dynamic_cast<Rectangle*>(objectStore->value(i))){
                Selection *selection = new RectSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->activeSelection = selection;
                return true;
            }
            else if (dynamic_cast<Line*>(objectStore->value(i))){
                Selection *selection = new LineSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->activeSelection = selection;
                return true;
            }
            else{
                Selection *selection = new GroupSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->activeSelection = selection;
                return true;
            }
        }
    }
    return false;
}

bool SelectionDealler::addSelection(int x, int y){
    for (int i = objectStore->length()-1; i >= 0; i--){
        if (objectStore->value(i)->inBody(x,y) == true){
            if (dynamic_cast<Rectangle*>(objectStore->value(i))){
                Selection *selection = new RectSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->activeSelection = selection;
                return true;
            }
            else if (dynamic_cast<Line*>(objectStore->value(i))){
                Selection *selection = new LineSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->activeSelection = selection;
                return true;
            }
            else {
                Selection *selection = new GroupSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->activeSelection = selection;
                return true;
            }
        }
    }
    return false;
}
void SelectionDealler::tryMoove(int x, int y){
    if (selectionStore->activeSelection != NULL){
        selectionStore->activeSelection->tryMove(x,y);
    }
}
bool SelectionDealler::tryGrab(int x, int y){
    if (selectionStore->activeSelection->tryGrab(x,y)){
        return true;
    }
    else {
        return false;
    }
}


void SelectionDealler::del(){
//    for(int i = 0; i< selectionStore->length(); i++){
//        for(int j = 0; j< objectStore->length(); j++){
//            if (objectStore->value(j) == selectionStore->value(i)->object){
//                objectStore->removeAt(j);
////                selectionStore->remove(i);
//            }
//        }
//    }
//    selectionStore->Release();
    for(int i = 0; i< list->length(); i++){
        for(int j = 0; j< objectStore->length(); j++){
            if (objectStore->value(j) == list->value(i)){
                objectStore->removeAt(j);
                //                selectionStore->remove(i);
            }
        }
    }
    selectionStore->Release();
//    selectionStore->activeSelection = NULL;
//    selectionStore->Release();
}
void SelectionDealler::group(){
    groupDealler->group(list);
}

void SelectionDealler::unGroup(){

}

void SelectionDealler::Release(){
    selectionStore->Release();
}

void SelectionDealler::Draw(Painter* painter){
    selectionStore->draw(painter);
}
