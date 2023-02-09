#include "task_1.h"
#include "ui_task_1.h"

Task_1::Task_1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_1)
{
    ui->setupUi(this);
    parseText = new ParseText();
}

Task_1::~Task_1()
{
    delete ui;
    delete parseText;
    parseText = nullptr;
}

void ParseText::setText(QString t)
{
    text = t;
}

QChar ParseText::finder(QString symbol)
{
    if (symbol == list[0])
        return QChar(0x00A9);
    if (symbol == list[1])
        return QChar(0x2030);
    if (symbol == list[2])
        return QChar(0xAE);
    if (symbol == list[3])
        return QChar(0x20AC);
    if (symbol == list[4])
        return QChar(0x20BD);
}

QString ParseText::fixText()
{
    pos = 0;
    qint32 curPos;
    for (auto& it : list)
    {
        curPos = text.indexOf(it, pos);
        if (curPos != -1)
        {
            text.insert(curPos, finder(text.mid(curPos, size)));
            pos = curPos + 1;
            text.remove(pos, size);
            return text;
        }
    }

    return "";
}

void Task_1::on_plainTextEdit_textChanged()
{
    parseText->setText(ui->plainTextEdit->toPlainText());
    QString newText = parseText->fixText();
    if (newText != "")
        ui->plainTextEdit->setPlainText(newText);
    QTextCursor cursor = ui->plainTextEdit->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->plainTextEdit->setTextCursor(cursor);
}

void Task_1::on_pushButton_clicked()
{
    close();
}

