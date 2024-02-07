#include "group.h"
#include "qdebug.h"
#include "frame.h"


Group::Group(Frame *frame1) : GrObject(frame1)
{
//    group = new QVector<Figure*>();
    frame = frame1;
    gr = new QList<GrObject*>;
}

void Group::addToGroup(GrObject* obj){
    gr->append(obj);
}

void Group::countKs(){
    for(int i = 0; i< gr->length(); i ++){
        if (dynamic_cast<Line*>(gr->value(i)) ){
            gr->value(i)->frame->kx1 = countK(gr->value(i)->frame->x1, frame->x1, frame->x2);
            gr->value(i)->frame->kx2 = countK(gr->value(i)->frame->x2, frame->x1, frame->x2);
            gr->value(i)->frame->ky1 = countK(gr->value(i)->frame->y1, frame->y1, frame->y2);
            gr->value(i)->frame->ky2 = countK(gr->value(i)->frame->y2, frame->y1, frame->y2);
//            qDebug() << gr->value(i)->frame->kx1 << "  " << gr->value(i)->frame->kx2;
        }
        if (dynamic_cast<Rectangle*>(gr->value(i)) ){
            gr->value(i)->frame->kx1 = countK(gr->value(i)->frame->x1, frame->x1, frame->x2);
            gr->value(i)->frame->kx2 = countK(gr->value(i)->frame->x1 + gr->value(i)->frame->x2, frame->x1, frame->x2);
            gr->value(i)->frame->ky1 = countK(gr->value(i)->frame->y1, frame->y1, frame->y2);
            gr->value(i)->frame->ky2 = countK(gr->value(i)->frame->y1 + gr->value(i)->frame->y2, frame->y1, frame->y2);
//            qDebug() << gr->value(i)->frame->kx1 << "  " << gr->value(i)->frame->kx2;
        }
    }
}
QList <GrObject *> *Group::getList(){
    return gr;
}

void Group::draw(Painter * painter){
//    refactorCoordinats();
    for (int i = 0; i < gr->length(); i++){
        GrObject* object = gr->value(i);
        object->draw(painter);
    }
}

bool Group::inBody(int x, int y){
    for (int i = 0; i < gr->length(); i++){
        if(gr->value(i)->inBody(x,y) == true){
            return true;
        }
    }
    return false;
}
void Group::refactorCoordinats(int a, int b){
    for (int i = 0; i < gr->length(); i++){
        if (dynamic_cast<Line*>(gr->value(i)) ){
            gr->value(i)->frame->x1 = gr->value(i)->frame->x1 + gr->value(i)->frame->kx1*a;
            gr->value(i)->frame->x2 = gr->value(i)->frame->x2 + gr->value(i)->frame->kx2*a;
            gr->value(i)->frame->y1 = gr->value(i)->frame->y1 + gr->value(i)->frame->ky1*b;
            gr->value(i)->frame->y2 = gr->value(i)->frame->y2 + gr->value(i)->frame->ky2*b;
        }
        else if (dynamic_cast<Group*>(gr->value(i))){
            Group *grop = dynamic_cast<Group*>(gr->value(i));
            grop->refactorCoordinats(a, b);
        }
        else if (dynamic_cast<Rectangle*>(gr->value(i))){
            float xxx = gr->value(i)->frame->x1 + gr->value(i)->frame->x2;
            float yyy = gr->value(i)->frame->y1 + gr->value(i)->frame->y2;
            xxx = xxx + float(gr->value(i)->frame->kx2*a);
            yyy = yyy + float(gr->value(i)->frame->ky2*b);
            gr->value(i)->frame->x1 = gr->value(i)->frame->x1 + gr->value(i)->frame->kx1*a;
            gr->value(i)->frame->x2 = xxx - gr->value(i)->frame->x1;

            gr->value(i)->frame->y1 = gr->value(i)->frame->y1 + gr->value(i)->frame->ky1*b;
            gr->value(i)->frame->y2 = yyy - gr->value(i)->frame->y1;
        }
    }
    frame->x2 = frame->x2 + a;
    frame->y2 = frame->y2 + b;
}
void Group::changeCoords(int x, int y){
    for (int i = 0; i < gr->length(); i++){
        if (dynamic_cast<Line*>(gr->value(i)) ){
            gr->value(i)->frame->x1 += x;
            gr->value(i)->frame->x2 += x;
            gr->value(i)->frame->y1 += y;
            gr->value(i)->frame->y2 += y;
        }
        else if (dynamic_cast<Group*>(gr->value(i))){
            Group *grop = dynamic_cast<Group*>(gr->value(i));
            grop->changeCoords(x, y);
        }
        else if (dynamic_cast<Rectangle*>(gr->value(i))){
            gr->value(i)->frame->x1 += x;

            gr->value(i)->frame->y1 += y;
        }
    }
}


float  Group::countK(int x, int min, int max){
    return (x - min) / float(max - min);
}
