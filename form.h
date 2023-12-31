#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include "painter.h"
#include "figure.h"
#include "group.h"

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

    void on_pushButton_3_clicked();

private:
    Ui::Form *ui;
    Painter *newPainter;
//    Figure *line;
};
#endif // FORM_H
