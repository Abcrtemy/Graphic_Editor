#include "form.h"
#include "./ui_form.h"

Form::Form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    newPainter = new Painter(scene);
    ui->graphicsView->setScene(scene);
}

Form::~Form()
{
    delete ui;
}


void Form::on_pushButton_clicked()
{
    SetOfProps* props0 = new LineSetOfProps(Qt::white, Qt::DotLine, 5);
    SetOfProps* props1 = new FillSetOfProps(Qt::red);

    PropList *propList0 = new PropList();
    PropList *propList1 = new PropList();

    Frame *frame = new Frame(0,100,-100,200);
    Frame *frame1 = new Frame(100,100,-100,200);

    Figure* line = new Line(frame,propList0);
    Figure* rect = new Rectangle(frame1, propList1);

    rect->changeProps(props0, newPainter);
    rect->changeProps(props1, newPainter);
    line->changeProps(props0,newPainter);

    line->draw(newPainter);
    rect->draw(newPainter);
//    Figure* line3 = new Line(0,0,-100,-100);
//    line->changeLine(Qt::red,5, Qt::SolidLine);
////    line->changeFill(Qt::white);
//    line3->changeLine(Qt::red,5,Qt::DotLine);
//    line->draw(newPainter);
//    line3->draw(newPainter);
}


void Form::on_pushButton_2_clicked()
{
    SetOfProps* props0 = new LineSetOfProps(Qt::white, Qt::DotLine, 5);

    PropList *propList0 = new PropList();

    Frame *frame = new Frame(100,100,200,200);

    Figure* line = new Line(frame, propList0);

    line->changeProps(props0,newPainter);
    line->draw(newPainter);

//    rect->draw(newPainter);
//    Figure* rect1 = new Rectangle(100,0,100,100);
//    rect1->changeFill(Qt::green);
//    rect1->changeLine(Qt::white,6,Qt::DotLine);

//    rect1->draw(newPainter);

//    Figure* rect = new Rectangle(0,0,100,100);
//    rect->changeFill(Qt::red);
//    Figure* rect1 = new Rectangle(100,0,100,100);
//    rect1->changeFill(Qt::green);
//    rect1->changeLine(Qt::white,6,Qt::DotLine);
//    Figure* rect2 = new Rectangle(200,0,100,100);
//    rect2->changeFill(Qt::blue);
//    rect->draw(newPainter);
//    rect1->draw(newPainter);
//    rect2->draw(newPainter);
}


void Form::on_pushButton_3_clicked()
{

    SetOfProps* props0 = new LineSetOfProps(Qt::white, Qt::DotLine, 5);

    Frame *frame = new Frame(200,200,100,300);
    Frame *frame1 = new Frame(-100,200,0,300);

    PropList *propList0 = new PropList();
    PropList *propList1 = new PropList();

    Figure* line = new Line(frame, propList0);
    Figure* line1 = new Line(frame1, propList1);

    Group *gr1 = new Group(frame);
    Group *gr2 = new Group(frame);

    line->changeProps(props0,newPainter);
    gr1->addToGroup(line);
    gr2->addToGroup(gr1);
    gr2->addToGroup(line1);
    gr2->draw(newPainter);


//    line->draw(newPainter);
//    Group* group = new Group;
//    Group* group1 = new Group;
//    Figure* line1 = new Line(300,100,400,200);
//    Figure* line2 = new Line(300,0,400,-100);
//    Figure* line3 = new Line(-100,200,400,200);
//    line1->changeLine(Qt::blue,5,Qt::SolidLine);
//    line2->changeLine(Qt::blue,5,Qt::DotLine);
//    line3->changeLine(Qt::white,5,Qt::DotLine);
//    group->addToGroup(line1);
//    group->addToGroup(line2);
//    group1->addToGroup(line3);
//    group1->addToGroup(group);
//    group1->draw(newPainter);

}

