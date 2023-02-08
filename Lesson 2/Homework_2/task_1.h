#ifndef TASK_1_H
#define TASK_1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Task_1; }
QT_END_NAMESPACE

class ParseText;

class Task_1 : public QMainWindow
{
    Q_OBJECT

public:
    Task_1(QWidget *parent = nullptr);
    ~Task_1();

private slots:
    void on_plainTextEdit_textChanged();

    void on_pushButton_clicked();

private:
    Ui::Task_1 *ui;
    ParseText* parseText;
};

class ParseText
{
private:
    QString text;
    QString fixedText;
    qint32 pos;
    const QStringList list = { "#@CPR@", "#@PRM@", "#@REG@", "#@EUR@", "#@RUB@" };
    const qint8 size = 6;
    QChar finder(QString);
public:
    ParseText() = default;
    void setText(QString);
    QString fixText();
};

#endif // TASK_1_H
