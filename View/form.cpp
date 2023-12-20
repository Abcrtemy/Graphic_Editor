#include "form.h"
#include "./ui_form.h"


Form::Form(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
    scene = new GraphicsScene();
    newPainter = new Painter();
    scene->setSceneRect(0,0,776,510);
    newPainter->setPort(scene);
    ui->graphicsView->setScene(scene);
    model = new Model();
    controller = new Controller(model);

    connect(scene, &GraphicsScene::leftButtonPressed, this, &Form::onLeftButtonPressed);
    connect(scene, &GraphicsScene::leftButtonReleased, this, &Form::LeftButtonReleased);
    connect(scene, &GraphicsScene::MsMoved, this, &Form::mouseMoove);
    connect(scene, &GraphicsScene::ShiftMsUp, this, &Form::shiftMouseUp);
    connect(scene, &GraphicsScene::Del, this, &Form::Del);
    connect(scene, &GraphicsScene::ESC, this, &Form::Esc);
    paintController = controller->getPaintController();
    paintController->SetPort(scene);

    action = controller->getAction();

    collecton = controller->getCollection();

    factory = model->getFactory();
}

Form::~Form()
{
    delete ui;
}



void Form::onLeftButtonPressed(int x, int y){
    scene->clear();
    action->mouseDown(x, y);
    paintController->Refresh();
}


void Form::LeftButtonReleased(int x, int y){
    scene->clear();
    action->mouseUp(x, y);
    paintController->Refresh();
}

void Form::mouseMoove(int x, int y){
    scene->clear();
    action->mouseMoove(x, y);
    paintController->Refresh();
}

void Form::shiftMouseUp(int x, int y){
    scene->clear();
    action->shiftMouseUp(x, y);
    paintController->Refresh();
}
void Form::Esc(){
    scene->clear();
    action->esc();
    paintController->Refresh();
}
void Form::Del(){
    scene->clear();
    action->del();
    paintController->Refresh();
}



void Form::on_pushButton_clicked()
{
    action->setCreateObjectType(CreateObjectType::LineType);
    action->startCreate();
}


void Form::on_pushButton_2_clicked()
{
    action->setCreateObjectType(CreateObjectType::RectangleType);
    action->startCreate();
}

void Form::on_ChangeType_currentIndexChanged(int index)
{
    controller->ChangeProps(ui->Thickness->value(), index,fill,line);
}


void Form::on_Thickness_valueChanged(int arg1)
{
    controller->ChangeProps(arg1, ui->ChangeType->currentIndex(),fill,line);
}


void Form::on_LineColor_clicked()
{
    bool ok;
    QColor color = QColorDialog::getColor(Qt::white,this);
    if(&ok) {
        fill = color;
        controller->ChangeProps(ui->Thickness->value(), ui->ChangeType->currentIndex(),fill,line);
    }

}

void Form::on_FillColor_clicked()
{
    bool ok;
    QColor color = QColorDialog::getColor(Qt::white,this);
    if(&ok) {
        line = color;
        controller->ChangeProps(ui->Thickness->value(), ui->ChangeType->currentIndex(),fill,line);
    }
}


void Form::on_pushButton_3_clicked()
{
    scene->clear();
    action->group();
    paintController->Refresh();
}


void Form::on_pushButton_4_clicked()
{
    scene->clear();
    action->unGroup();
    paintController->Refresh();
}

