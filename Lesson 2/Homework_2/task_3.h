#ifndef TASK_3_H
#define TASK_3_H

#include <QMainWindow>
#include <QStandardItemModel>

namespace Ui {
class Task_3;
}

class Task_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Task_3(QWidget *parent = nullptr);
    ~Task_3();

private slots:
    void on_changeButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::Task_3 *ui;
    QStandardItemModel* model;
    QBrush* brush;
};

#endif // TASK_3_H
