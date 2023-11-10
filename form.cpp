#include "form.h"
#include "./ui_form.h"

Form::Form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    newPainter = new Painter();
    ui->graphicsView->setScene(newPainter);
}

Form::~Form()
{
    delete ui;
}


void Form::on_pushButton_clicked()
{
    SetOfProps* props0 = new LineSetOfProps(Qt::white, Qt::DotLine, 5);
    SetOfProps* props1 = new FillSetOfProps(Qt::red);
    Figure* line = new Line(0,100,-100,200);
    Figure* rect = new Rectangle(100,100,-100,200);
    rect->changeProps(props1, newPainter);
    rect->changeProps(props0, newPainter);
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

