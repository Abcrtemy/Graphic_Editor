#include "proplist.h"

//template <class T>
PropList::PropList()
{
    linePropsSet = new LineSetOfProps();
    fillPropsSet = new FillSetOfProps();


}
//template<class LineSetOfProps>
void PropList ::changeLinePropsSet(QColor newLineColor, int with, Qt::PenStyle style){
//    SetOfProps *prop = new LineSetOfProps();
    linePropsSet->changeLineProps(newLineColor, with, style); //д
    this->push_back(linePropsSet);
}
//template <class FillSetOfProps>
void PropList::changeFillPropsSet(QColor newFillColor){
    fillPropsSet->changeFillProps(newFillColor); // fuck
    this->push_back(fillPropsSet);

//    this->append(fillPropsSet->rgb());
}
