#include "selectiondealler.h"

SelectionDealler::SelectionDealler(SelectionStore *store, ObjectStore *objStore, GroupDealler *grDealler, ChangeDealler *chDealler)
{
    selectionStore = store;
    objectStore = objStore;
    list = store->getObjList();
    groupDealler = grDealler;
    changeDealler = chDealler;
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
                changeDealler->figureChange(objectStore->value(i));
                //
                break;
            }
            else if (dynamic_cast<Line*>(objectStore->value(i))){
                Selection *selection = new LineSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->tryGrab(x, y);
                changeDealler->figureChange(objectStore->value(i));
                break;
            }
            else {
                Selection *selection = new GroupSelection(objectStore->value(i));
                selectionStore->append(selection);
                list->append(objectStore->value(i));
                selectionStore->tryGrab(x, y);
                changeDealler->figureChange(objectStore->value(i));
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


void SelectionDealler::mooveFigure(int x, int y){
    int a = x - globalX;
    int b = y - globalY;
    globalX = x;
    globalY = y;
    if (selectionStore->length() != 0){
        for(int i = 0; i< selectionStore->length(); i++){
            if(selectionStore->value(i)->object->inBody(x,y) == true){
                selectionStore->mooveFigure(a, b);
            }
        }
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
    for(int i = 0; i< list->length(); i++){
        for(int j = 0; j< objectStore->length(); j++){
            if (objectStore->value(j) == list->value(i)){
                changeDealler->figureChange(objectStore->value(j));
                objectStore->removeAt(j);
            }
        }
    }
    selectionStore->Release();
}
void SelectionDealler::group(){
    selectionStore->Release();
    groupDealler->group(list);
    for (int i = objectStore->length()-1; i >= 0; i--){
        if (dynamic_cast<Group*>(objectStore->value(i))){
            Selection *selection = new GroupSelection(objectStore->value(i));
            changeDealler->groupChange(dynamic_cast<Group*>(objectStore->value(i)));
            selectionStore->append(selection);
            list->clear();
            list->append(objectStore->value(i));
            selectionStore->activeSelection = selection;
            break;
        }
    }

}

void SelectionDealler::unGroup(){
    list->clear();
    for (int i = selectionStore->length()-1; i >= 0; i--){
        if (dynamic_cast<GroupSelection*>(selectionStore->value(i))){
            for (int j = objectStore->length()-1; j >= 0; j--){
                if (selectionStore->value(i)->object == objectStore->value(j)){
                    Group *groupe = dynamic_cast<Group*>(objectStore->value(j));
                    changeDealler->groupChange(groupe);
                    for(int h = 0; h < groupe->gr->length(); h++){
                        list->append(groupe->gr->value(h));
                    }
                    objectStore->removeAt(j);
                    selectionStore->removeAt(i);
                    groupDealler->unGroup(groupe);
                }
            }
        }
    }
}

void SelectionDealler::Release(){
    selectionStore->Release();
}

void SelectionDealler::Draw(Painter* painter){
    selectionStore->draw(painter);
}
void SelectionDealler::rememberCoordinats(){
//    selectionStore->activeSelection->object->frame;
    Frame *framee = new Frame(0,0,0,0);
    *framee = *selectionStore->activeSelection->object->frame;
    changeDealler->transformChange(selectionStore->activeSelection->object, framee);
}




//    list->clear();
//    for (int i = selectionStore->length()-1; i >= 0; i--){
//        if (dynamic_cast<GroupSelection*>(selectionStore->value(i))){
//            for (int j = objectStore->length()-1; j >= 0; j--){
//                if (selectionStore->value(i)->object == objectStore->value(j)){
//                    Group *groupe = dynamic_cast<Group*>(objectStore->value(j));
//                    for(int h = 0; h < groupe->gr->length(); h++){
//                        list->append(groupe->gr->value(h));
//                    }
//                    objectStore->removeAt(j);
//                    selectionStore->removeAt(i);
//                    for (int z = list->length()-1; z >= 0; z--){
//                        if (dynamic_cast<Rectangle*>(list->value(z))){
//                            Selection *selection = new RectSelection(list->value(z));
//                            selectionStore->append(selection);
//                            selectionStore->activeSelection = selection;
//                            objectStore->append(list->value(z));
//                        }
//                        else if (dynamic_cast<Line*>(list->value(z))){
//                            Selection *selection = new LineSelection(list->value(z));
//                            selectionStore->append(selection);
//                            selectionStore->activeSelection = selection;
//                            objectStore->append(list->value(z));
//                        }
//                        else if (dynamic_cast<Group*>(list->value(z))){
//                            Selection *selection = new GroupSelection(list->value(z));
//                            selectionStore->append(selection);
//                            selectionStore->activeSelection = selection;
//                            objectStore->append(list->value(z));
//                        }
//                    }
//                }
//            }
//        }
//    }
