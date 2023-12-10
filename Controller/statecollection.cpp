#include "statecollection.h"
#include <QAction>

#include <functional>

StateCollection::StateCollection(IModel *model)
{

    dragState = new DragState(model);
    createState = new CreateState(model);
    this->append(createState);
    this->append(dragState);
    nowState = createState;
//    connect(dragState, SIGNAL(changeToCreate), this, SLOT(StateCollection::changetoCreate));
//    connect(createState, SIGNAL(CreateState::changeToDrag), this, SLOT(StateCollection::changeToDrag));
}

void StateCollection::mouseUp(int x, int y){
//    if (nowState == crState){
//        this->value(0)->MouseUp(x,y);
//        nowState = drState;
//    }
//    else {
//        this->value(1)->MouseUp(x,y);
//        nowState = crState;
//    }
    //    void (*callBack)() = &StateCollection::changeToDrag;
    std::function<void()> callBack = [this](){ changetoCreate(); };

//    std::function<void()> callBack = std::bind(&StateCollection::changetoCreate(), this);
//    std::function<void()> callback = [this]() { this->changeToDrag();};
    nowState->MouseUp(x, y, callBack);

}

void StateCollection::mouseDown(int x, int y){
//    if (nowState == crState){
//        this->value(0)->MouseDown(x,y);
//        nowState = drState;
//    }
//    else {
//        this->value(1)->MouseDown(x,y);
//        nowState = crState;
//    }
//    std::function<void()> callBack = std::bind(&StateCollection::changeToDrag(), this);
//    nowState->MouseUp(x, y, callBack);
    std::function<void()> callBack = [this](){ changeToDrag(); };
    nowState->MouseDown(x, y,callBack);
}
void StateCollection::mouseMoove(int x, int y){
//    if (nowState == crState){
//        this->value(0)->MouseMove(x,y);
////        nowState = drState;
//    }
//    else {
//        this->value(1)->MouseMove(x,y);
////        nowState = crState;
//    }
    nowState->MouseMove(x, y);
}


void StateCollection::changetoCreate(){
    nowState = createState;
}
void StateCollection::changeToDrag(){
    nowState = dragState;
}

//class MyClass {
//public:
//    void callbackMethod(int result) {
////        std::cout << "Результат: " << result << std::endl;
//    }
//};

//typedef void (MyClass::*CallbackMethod)(int);

//void performCallback(CallbackMethod callback, MyClass* obj) {
//    int result = 10;
//    (obj->*callback)(result);
//}

//int main() {
//    MyClass obj;
//    CallbackMethod cb = &MyClass::callbackMethod;
//    performCallback(cb, &obj);
//    return 0;
//}

