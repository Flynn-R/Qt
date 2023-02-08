#include "task_2.h"
#include "ui_task_2.h"

Task_2::Task_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task_2)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->listView->setModel(model);

    model->appendRow(new QStandardItem(QIcon("../Homework_2/Icons/C++.png"), "C++"));
    model->appendRow(new QStandardItem(QIcon("../Homework_2/Icons/Python.png"), "Python"));
    model->appendRow(new QStandardItem(QIcon("../Homework_2/Icons/Java.png"), "Java"));
    model->appendRow(new QStandardItem(QIcon("../Homework_2/Icons/C#.png"), "C#"));
    model->appendRow(new QStandardItem(QIcon("../Homework_2/Icons/PHP.png"), "PHP"));
    model->appendRow(new QStandardItem(QIcon("../Homework_2/Icons/JavaScript.png"), "JavaScript"));

    ui->listView->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
}

Task_2::~Task_2()
{
    delete ui;
    delete model;
}

void Task_2::on_upButton_clicked()
{
    auto curRow = ui->listView->currentIndex().row();
    if (curRow > 0)
    {
        auto curItem = model->takeItem(curRow);
        model->removeRow(curRow--);

        auto prevItem = model->takeItem(curRow);
        model->removeRow(curRow);
        model->insertRow(curRow, curItem);
        model->insertRow(curRow + 1, prevItem);
        ui->listView->setCurrentIndex(model->indexFromItem(model->item(curRow)));
    }
}


void Task_2::on_downButton_clicked()
{
    auto curRow = ui->listView->currentIndex().row();
    if (curRow != model->rowCount() - 1 && curRow != -1)
    {
        auto curItem = model->takeItem(curRow);
        model->removeRow(curRow);

        auto nextItem = model->takeItem(curRow);
        model->removeRow(curRow);
        model->insertRow(curRow, nextItem);
        model->insertRow(curRow + 1, curItem);
        ui->listView->setCurrentIndex(model->indexFromItem(model->item(curRow + 1)));
    }
}


void Task_2::on_addButton_clicked()
{
    QString text = ui->lineEdit->text();
    if (text != "")
        model->appendRow(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)), text));
    ui->lineEdit->clear();
}


void Task_2::on_deleteButton_clicked()
{
    auto curRow = ui->listView->currentIndex().row();
    if (curRow >= 0)
        model->removeRow(curRow);
}


void Task_2::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 2)
        ui->listView->setViewMode(QListView::IconMode);
    else
        ui->listView->setViewMode(QListView::ListMode);
}


void Task_2::on_nextButton_clicked()
{
    close();
}

