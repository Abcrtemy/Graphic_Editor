#ifndef PROPDEALER_H
#define PROPDEALER_H
#include <QPen>
#include "factory.h"
#include "setofprops.h"

class IPropDealler
{
public:
    virtual void changeProps(int width, int index, QColor lineColor, QColor fillColor) = 0;
};

class PropDealer : public IPropDealler
{
public:
    PropDealer(IFactory *nFactory);
    void changeProps(int width, int index, QColor lineColor, QColor fillColor) override;
private:
    IFactory *factory;
//    LineSetOfProps lineProps;
//    FillSetOfProps fillProps;
};

#endif // PROPDEALER_H
