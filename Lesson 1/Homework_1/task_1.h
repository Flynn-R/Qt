#ifndef TASK_1_H
#define TASK_1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Task_1; }
QT_END_NAMESPACE

class Task_1 : public QMainWindow
{
    Q_OBJECT

public:
    Task_1(QWidget *parent = nullptr);
    ~Task_1();

private slots:
    void on_calcButton_clicked();

    void on_nextTaskButton_clicked();

private:
    Ui::Task_1 *ui;
};
#endif // TASK_1_H
