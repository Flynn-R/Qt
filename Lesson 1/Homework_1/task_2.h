#ifndef TASK_2_H
#define TASK_2_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Task_2; }
QT_END_NAMESPACE

class Task_2 : public QMainWindow
{
    Q_OBJECT

public:
    Task_2(QWidget *parent = nullptr);
    ~Task_2();

private slots:
    void on_calcButton_clicked();

    void on_nextTaskButton_clicked();

private:
    Ui::Task_2 *ui;
};
#endif // TASK_2_H
