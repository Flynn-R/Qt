#include "organizer.h"
#include <QTextStream>

Organizer::Organizer(QObject *parent)
    : QObject{parent}
{
    file = new QFile("../Organizer/tasks.txt");
    if (!file)
        return;

    if (file->open(QIODevice::WriteOnly | QIODevice::Append))
        emit fileLoaded(true);
    else
        emit fileLoaded(false);
}

Organizer::~Organizer()
{
    if (file)
    {
        file->close();
        delete file;
    }
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
                taskList.append("\"" + name + "\"" + " must be completed until " + date + "; current progress: " + progress + "/10\n");
        }
    }
}

void Organizer::writeToFile()
{
    if (!taskList.isEmpty())
    {
        QTextStream stream(file);
        for (auto& it : taskList)
            stream << it;
    }
}
