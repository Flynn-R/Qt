#include "task_1.h"
#include "ui_task_1.h"
#include <QtMath>

Task_1::Task_1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_1)
{
    ui->setupUi(this);
}

Task_1::~Task_1()
{
    delete ui;
}


void Task_1::on_calcButton_clicked()
{
    double a = ui->aLineEdit->text().toDouble();
    double b = ui->bLineEdit->text().toDouble();
    double c = ui->cLineEdit->text().toDouble();

    QString equation;
    QString result;
    if (a != 0)
    {
        if (b != 0)
        {
            if (c != 0)
                equation = QString::number(a) + "x^2" + (b > 0 ? " + " + QString::number(b) : " - " + QString::number(-b)) + "x" + (c > 0 ? " + " : " - ") + QString::number(c) + " = 0";
            else
                equation = QString::number(a) + "x^2" + (b > 0 ? " + " + QString::number(b) : " - " + QString::number(-b)) + "x" + " = 0";
        }
        else
        {
            if (c != 0)
                equation = QString::number(a) + "x^2" + (c > 0 ? " + " + QString::number(c) : " - " + QString::number(-c)) + " = 0";
            else
                equation = QString::number(a) + "x^2" + " = 0";
        }

        double d = qPow(b, 2) - 4 * a * c;
        double x1, x2;
        QString complexX1, complexX2;
        if (d >= 0)
        {
            x1 = (-b + qSqrt(d)) / (2 * a);
            x2 = (-b - qSqrt(d)) / (2 * a);

            if (x1 != x2)
                result = "Результат: x1 = " + QString::number(x1) + "; x2 = " + QString::number(x2);
            else
                result = "Результат: x = " + QString::number(x1);
        }
        else
        {
            complexX1 = (b != 0 ? QString::number(-b / (2 * a)) : "") + " + " + QString::number((qSqrt(-d) / (2 * a))) + "i";
            complexX2 = (b != 0 ? QString::number(-b / (2 * a)) : "") + " - " + QString::number((qSqrt(-d) / (2 * a))) + "i";

            result = "Результат: x1 = " + complexX1 + "; x2 = " + complexX2;
        }
    }
    else
    {
        if (b != 0)
        {
            if (c != 0)
                equation = QString::number(b) + "x" + (c > 0 ? " + " + QString::number(c) : " - " + QString::number(-c)) + " = 0";
            else
                equation = QString::number(b) + "x = 0";

            double x = -c / b;

            result = "Результат: x = " + QString::number(x);
        }
        else
        {
            if (c != 0)
                equation = "Wrong equation!\n";
            else
                equation = "0 = 0";

            result = "Результат: нет корней.";
        }
    }

    ui->equationLabel->setText(equation);
    ui->xLabel->setText(result);
}


void Task_1::on_nextTaskButton_clicked()
{
    this->close();
}

