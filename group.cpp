#include "group.h"
#include "qdebug.h"
#include "frame.h"


//Group::Group()
//{
////    group = new QVector<Figure*>();

//    gr = new QList<GrObject*>;
//}

void Group::addToGroup(GrObject* obj){
    gr->append(obj);

//    if (dynamic_cast<Rectangle*>(figure)){
//        Rectangle* rect = dynamic_cast<Rectangle*>(figure);
//        group->push_back(rect);
//        qDebug() << "Rect";
//    }
//    else{
//        Line* line = dynamic_cast<Line*>(figure);
//        group->push_back(line);
//        qDebug() << "Line";
//    }
//    group->push_back(figure);
//    qDebug() << "sfvsfv";
}
void Group::draw(Painter * painter){
//    int l = gr->length();
    for (int i = 0; i < gr->length(); i++){
        GrObject* object = gr->value(i);
        if (dynamic_cast<Rectangle*>(object)){
            Rectangle* rect = dynamic_cast<Rectangle*>(object);
            rect->draw(painter);
        }
        else if (dynamic_cast<Group*>(object)){
            Group* grope = dynamic_cast<Group*>(object);
            grope->draw(painter);
        }
        else{
            Line* line = dynamic_cast<Line*>(object);
            line->draw(painter);
        }
    }
}
