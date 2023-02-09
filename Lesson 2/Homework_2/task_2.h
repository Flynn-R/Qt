#ifndef TASK_2_H
#define TASK_2_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class Task_2;
}

class Task_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task_2(QWidget *parent = nullptr);
    ~Task_2();

private slots:


    void on_upButton_clicked();

    void on_downButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_nextButton_clicked();

private:
    Ui::Task_2 *ui;
    QStandardItemModel* model;
};

#endif // TASK_2_H
