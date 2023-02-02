#include "task_2.h"
#include "ui_task_2.h"
#include "QtMath"

Task_2::Task_2(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_2)
{
    ui->setupUi(this);
}

Task_2::~Task_2()
{
    delete ui;
}

void Task_2::on_calcButton_clicked()
{
    double a = ui->aLineEdit->text().toDouble();
    double b = ui->bLineEdit->text().toDouble();
    double angle = ui->angleLineEdit->text().toDouble();

    if (a > 0 && b > 0 && angle > 0)
    {
        if (ui->degRadioButton->isChecked())
            angle = qDegreesToRadians(angle);
        QString result = "Результат: " + QString::number(qSqrt(qPow(a, 2) + qPow(b, 2) - 2 * a * b * qCos(angle)));
        ui->resLabel->setText(result);
    }
    else
        ui->resLabel->setText("Неверные данные!");
}

void Task_2::on_nextTaskButton_clicked()
{
    this->close();
}

