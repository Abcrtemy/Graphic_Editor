#include "selectionstore.h"

SelectionStore::SelectionStore()
{

}

void SelectionStore::tryGrab(int x, int y){
    for(int b = this->count()-1; b>=0; b--){
        if(this->value(b)->tryGrab(x, y)){
            activeSelection = this->value(b);
        }
    }
//    int b = this->count() - 1;
//    this->value(b);
//    activeSelection = this->value(b);
}
bool SelectionStore::tryMove(){

}
void SelectionStore::Release(){
    activeSelection = NULL;
}
void SelectionStore::draw (Painter *painter){
    if (activeSelection != NULL){
        activeSelection->Draw(painter);
    }
}
