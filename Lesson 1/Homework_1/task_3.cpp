#include "task_3.h"
#include "ui_task_3.h"
#include <QTextEdit>

Task_3::Task_3(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_3)
{
    ui->setupUi(this);
}

Task_3::~Task_3()
{
    delete ui;
}

void Task_3::on_addButton_clicked()
{
    QString w1 = ui->plainTextEdit->toPlainText();
    QString w2 = ui->plainTextEdit_2->toPlainText();
    ui->plainTextEdit_2->setPlainText(w2 + w1);
}


void Task_3::on_setButton_clicked()
{
    ui->plainTextEdit->setPlainText(ui->plainTextEdit_2->toPlainText());
}


void Task_3::on_htmlButton_clicked()
{
    QTextEdit text;
    text.setHtml("<font color='red'>Hello</font>");
    ui->plainTextEdit->setPlainText(text.toPlainText() + ui->plainTextEdit->toPlainText());
}


void Task_3::on_exitButton_clicked()
{
    this->close();
}

