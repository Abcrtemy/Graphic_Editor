#include "proplist.h"


//template <class T>
PropList::PropList()
{
//    linePropsSet = new LineSetOfProps();
//    fillPropsSet = new FillSetOfProps();


}

void PropList::addSet(SetOfProps *propset, Painter* painter){
    this->push_back(propset);
    applySets(painter);
}
void PropList::applySets(Painter * painter){
    for (int i = 0; i <this->length(); i++) {
        if (dynamic_cast<LineSetOfProps*>(this->value(i))){
            SetOfProps* SetPropsl = this->value(i);
            LineSetOfProps* lineProps = dynamic_cast<LineSetOfProps*>(SetPropsl);
            painter->pen.setColor(lineProps->color);
            painter->pen.setWidth(lineProps->with);
            painter->pen.setStyle(lineProps->style);
        }
        else if(dynamic_cast<FillSetOfProps*>(this->value(i))){
            SetOfProps* SetPropsf = this->value(i);
            FillSetOfProps* fillProps = dynamic_cast<FillSetOfProps*>(SetPropsf);
            painter->brush.setColor(fillProps->fillColor);
            painter->brush.setStyle(Qt::SolidPattern);
        }
    }
}
//template<class LineSetOfProps>
//void PropList ::changeLinePropsSet(QColor newLineColor, int with, Qt::PenStyle style){
////    SetOfProps *prop = new LineSetOfProps();
//    linePropsSet->changeLineProps(newLineColor, with, style); //д
//    this->push_back(linePropsSet);
//}
////template <class FillSetOfProps>
//void PropList::changeFillPropsSet(QColor newFillColor){
//    fillPropsSet->changeFillProps(newFillColor); // fuck
//    this->push_back(fillPropsSet);

////    this->append(fillPropsSet->rgb());
//}
