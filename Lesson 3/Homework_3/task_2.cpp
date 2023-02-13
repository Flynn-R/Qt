#include "task_2.h"
#include "ui_task_2.h"

Task_2::Task_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Task_2)
{
    ui->setupUi(this);
    html = nullptr;
    file = nullptr;
}

Task_2::~Task_2()
{
    delete ui;
    if (html != nullptr) delete html;
}

void Task_2::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть HTML файл", QDir::homePath(), "HTML(*.html)");
    if (!fileName.isEmpty())
    {
        if (file != nullptr)
        {
            file->close();
            delete file;
        }
        file = new QFile(fileName);

        if (file->open(QIODevice::ReadOnly))
        {
            if (html != nullptr) delete html;
            html = new QTextStream(file);

            QStringList data = parser();

            ui->weather->setText(data.first());
            data.pop_front();
            ui->usd->setText(data.first());
            data.pop_front();
            ui->eur->setText(data.first());
            data.pop_front();
        }
    }
}

QStringList Task_2::parser()
{
    QStringList list;
    QString data = html->readAll();

    QString str = "class=\"weather__temp ccj-bcbg-4uusib\" data-testid=\"weather-temp\">";
    qint32 posBegin = data.indexOf(str);
    qint32 posEnd = data.indexOf("</span>", posBegin);
    list.append(data.mid(posBegin + str.length(), posEnd - posBegin - str.length()) + 'C');

    str.clear();
    str = "<div class=\"rate__currency ccj-bcbg-ov6yem\">";
    posBegin = data.indexOf(str);
    posEnd = data.indexOf("</div>", posBegin);
    list.append(data.mid(posBegin + str.length(), posEnd - posBegin - str.length()));

    posBegin = data.indexOf(str, posEnd);
    posEnd = data.indexOf("</div", posBegin);
    list.append(data.mid(posBegin + str.length(), posEnd - posBegin - str.length()));

    return list;
}
void Task_2::on_closeButton_clicked()
{
    close();
}

