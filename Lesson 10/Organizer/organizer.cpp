#include "organizer.h"
#include <QTextStream>

Organizer::Organizer(QObject *parent)
    : QObject{parent}
{
    file = new QFile("../Organizer/tasks.txt");
}

Organizer::~Organizer()
{
    if (file)
        delete file;
}

void Organizer::addNewTask(QString name, QString date, QString progress)
{
    if (!name.isEmpty())
    {
        QDate d = QDate::fromString(date, "dd.MM.yyyy");
        if (d.isValid())
        {
            qint32 p = progress.toInt();
            if (p >= 0 && p <= 10)
            {
                taskList.append("\"" + name + "\"" + " must be completed until " + date + "; current progress: " + progress + "/10\n");
                return;
            }
        }
    }

    emit incorrectData();
}

void Organizer::writeToFile()
{
    if (file->open(QIODevice::WriteOnly | QIODevice::Append))
        emit fileLoaded(true);
    else
        emit fileLoaded(false);

    if (!taskList.isEmpty())
    {
        QTextStream stream(file);
        for (auto& it : taskList)
            stream << it;
    }

    file->close();
}

QString Organizer::currentStatus()
{
    if (file->open(QIODevice::ReadOnly))
        emit fileLoaded(true);
    else
        emit fileLoaded(false);

    qint32 recent = taskList.count();
    qint32 total = recent + file->readAll().split('\n').count() - 1;

    file->close();
    return "Recently added: " + QString::number(recent) + ". Total: " + QString::number(total);
}
