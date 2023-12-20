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
//    int kx1 = 0;
//    int ky1 = 0;
//    int kx2 = 0;
//    int ky2 = 0;
    for (int i = 0; i < gr->length(); i++){
//        qDebug() << "afsdvkmosdfvnodsfnv";
//        qDebug() << a;
//        qDebug() << countK(gr->value(i)->frame->x1, frame->x1, frame->x2);
        gr->value(i)->frame->x1 = gr->value(i)->frame->x1 + countK(gr->value(i)->frame->x1, frame->x1, frame->x2)*a;
        gr->value(i)->frame->x2 = gr->value(i)->frame->x2 + countK(gr->value(i)->frame->x2, frame->x1, frame->x2)*a;
        gr->value(i)->frame->y1 = gr->value(i)->frame->y1 + countK(gr->value(i)->frame->y1, frame->y1, frame->y2)*b;
        gr->value(i)->frame->y2 = gr->value(i)->frame->y2 + countK(gr->value(i)->frame->y2, frame->y1, frame->y2)*b;
//        gr->value(i)->frame->x1 = (gr->value(i)->frame->x1 - frame->x1) * ((frame->x2-frame->x1)/(frame->x2+a-frame->x1)) +  frame->x1;
// Новая координата X = (Старая координата X - Старая координата верхнего левого угла общей рамки) * (Новая ширина общей рамки / Старая ширина общей рамки) + Новая координата верхнего левого угла общей рамки


//        gr->value(i)->frame->x1 = gr->value(i)->frame->x1 + a;
//        gr->value(i)->frame->x2 = gr->value(i)->frame->x2 + a;
//        gr->value(i)->frame->y1 = gr->value(i)->frame->y1 + b;
//        gr->value(i)->frame->y2 = gr->value(i)->frame->y2 + b;
    }
    frame->x2 = frame->x2 + a;
    frame->y2 = frame->y2 + b;
}
float  Group::countK(int x, int min, int max){
//    qDebug() << x;
//    qDebug() << min;
//    qDebug() << max;
//    qDebug() << "координаты";

    return (x - min) / float(max - min);
}
