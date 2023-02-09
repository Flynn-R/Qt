#ifndef TASK_2_H
#define TASK_2_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

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
    void on_openButton_clicked();

    void on_closeButton_clicked();

private:
    Ui::Task_2 *ui;
    QTextStream* html;
    QStringList parser();
    QFile* file;
};

#endif // TASK_2_H
