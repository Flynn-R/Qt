#include "task_3.h"
#include "ui_task_3.h"

Task_3::Task_3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task_3)
{
    ui->setupUi(this);

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);

    model->setHorizontalHeaderLabels(QStringList() << "№" << "Имя компьютера" << "IP адрес" << "MAC адрес");
    brush = new QBrush(model->horizontalHeaderItem(0)->background());

    QList<QStandardItem*> list1;
    list1.append(new QStandardItem("1"));
    list1.append(new QStandardItem("Дом"));
    list1.append(new QStandardItem("172.88.68.2"));
    list1.append(new QStandardItem("02:42:66:eb:aa:28"));
    model->appendRow(list1);

    QList<QStandardItem*> list2;
    list2.append(new QStandardItem("2"));
    list2.append(new QStandardItem("Работа"));
    list2.append(new QStandardItem("86.122.33.78"));
    list2.append(new QStandardItem("02:42:66:ee:32:af"));
    model->appendRow(list2);

    QList<QStandardItem*> list3;
    list3.append(new QStandardItem("3"));
    list3.append(new QStandardItem("Бубба"));
    list3.append(new QStandardItem("0.0.0.0"));
    list3.append(new QStandardItem("ff:ff:ff:ff:ff:ff"));
    model->appendRow(list3);
}

Task_3::~Task_3()
{
    delete ui;
    delete model;
    delete brush;
}

void Task_3::on_changeButton_clicked()
{
    auto curRow = ui->tableView->currentIndex().row();
    auto curBrush = model->item(curRow)->background();
    if (curRow >= 0)
    {
        if (curBrush == *brush)
            curBrush = Qt::GlobalColor::darkCyan;
        else
            curBrush = *brush;

        for (auto i = 0; i < model->columnCount(); ++i)
            model->item(curRow, i)->setBackground(curBrush);
    }
}


void Task_3::on_closeButton_clicked()
{
    close();
}

