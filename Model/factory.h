#ifndef FACTORY_H
#define FACTORY_H

#include "proplist.h"
#include "figure.h"
#include "frame.h"
#include "objectstore.h"



class Factory
{
public:
    Factory(ObjectStore *newStore);
    void createItem ();
    ObjectStore *store;
private:

};

#endif // FACTORY_H
//Frame *frame, PropList *proplist
