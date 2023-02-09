#include "task_1.h"
#include "ui_task_1.h"

Task_1::Task_1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Task_1)
{
    ui->setupUi(this);
}

Task_1::~Task_1()
{
    delete ui;
}


void Task_1::on_nextButton_clicked()
{
    close();
}


void Task_1::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Сохранить текстовый файл", QDir::homePath(), "Текст (*.txt)");
    if (!fileName.isEmpty())
    {
        QString ext = ".txt";
        if (!(fileName.indexOf(".txt") == fileName.length() - ext.length()))
            fileName += ".txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&file);
            stream << ui->plainTextEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}


void Task_1::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть текстовый файл", QDir::homePath(), "Текст (*.txt)");
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
        }
    }
}


void Task_1::on_helpButton_clicked()
{
    QFile help(":/help/help.txt");
    if (help.open(QIODevice::ReadOnly))
    {
        QMessageBox messageBox;
        QTextStream stream(&help);
        messageBox.setText(stream.readAll());
        messageBox.exec();
    }
}
