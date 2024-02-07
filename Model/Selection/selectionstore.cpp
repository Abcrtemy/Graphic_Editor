#include "selectionstore.h"

SelectionStore::SelectionStore()
{
    list = new QList<GrObject*>;
}

void SelectionStore::tryGrab(int x, int y){
    for(int b = this->count()-1; b>=0; b--){
        if(this->value(b)->tryGrab(x, y)){
            activeSelection = this->value(b);
        }
    }
}
bool SelectionStore::tryMove(){

}
void SelectionStore::mooveFigure(int x, int y){
//    int a = 10;
//    int b = 10;
    for(int i = this->count()-1; i>=0; i--){
        this->value(i)->mooveFigure(x, y);
    }
}
void SelectionStore::Release(){
    this->clear();
    activeSelection = NULL;
}
void SelectionStore::draw (Painter *painter){
    if (this->length() != 0){
        for (int i = 0; i < this->length(); i++ ){
            this->value(i)->Draw(painter);
        }
    }
}

QList<GrObject*> *SelectionStore::getObjList() {
    return list;
}
