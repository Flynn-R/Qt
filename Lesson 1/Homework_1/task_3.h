#ifndef TASK_3_H
#define TASK_3_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Task_3; }
QT_END_NAMESPACE

class Task_3 : public QMainWindow
{
    Q_OBJECT

public:
    Task_3(QWidget *parent = nullptr);
    ~Task_3();

private slots:

    void on_addButton_clicked();

    void on_setButton_clicked();

    void on_htmlButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::Task_3 *ui;
};
#endif // TASK_3_H
