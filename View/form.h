#ifndef FORM_H
#define FORM_H

#include <QColorDialog>
#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsSceneEvent>
#include "graphicsscene.h"
#include "../Model/painter.h"
#include "../Model/figure.h"
#include "../Model/group.h"
#include "../Model/setofprops.h"
#include "../Model/frame.h"
#include "../Model/proplist.h"
#include "../Model/model.h"

#include "../Model/factory.h"
#include "../Model/paintcontroller.h"
#include "../Controller/controller.h"
#include "../Controller/action.h"
#include "../Controller/statecollection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Form; }
QT_END_NAMESPACE

class Form : public QMainWindow
{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
//    void on_pushButton_3_clicked();
    void onLeftButtonPressed(int x, int y);
    void LeftButtonReleased(int x, int y);
    void mouseMoove(int x, int y);
    void shiftMouseUp(int x, int y);
    void Esc();
    void Del();

    void on_ChangeType_currentIndexChanged(int index);

    void on_Thickness_valueChanged(int arg1);

    void on_LineColor_clicked();

    void on_FillColor_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Form *ui;
    Painter *newPainter;
    GraphicsScene *scene;
    IController *controller;
    IAction *action;
    StateCollection *collecton;
    IModel *model;
    IPaintController *paintController;
    IFactory *factory;
    QColor fill;
    QColor line;



//    Figure *line;
};
#endif // FORM_H
