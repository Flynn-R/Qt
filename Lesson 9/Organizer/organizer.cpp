#include "organizer.h"
#include <QTextStream>

Organizer::Organizer(QObject *parent)
    : QObject{parent}
{
    file = new QFile("../Organizer/tasks.txt");
    if (!file)
        return;

    if (!file->open(QIODevice::WriteOnly | QIODevice::Append))
        emit fileLoaded(false);
    else
        emit fileLoaded(true);
}

Organizer::~Organizer()
{
    if (file)
    {
        file->close();
        delete file;
    }
}

void Organizer::writeNewTask(QString name, QString date, QString progress)
{
    QTextStream stream(file);

    if (!name.isEmpty())
    {
        QDate d = QDate::fromString(date, "dd.MM.yyyy");
        if (d.isValid())
        {
            qint32 p = progress.toInt();
            if (p >= 0 && p <= 10)
                stream << "\"" + name + "\"" << " must be completed until " << date << "; current progress: " << progress << "/10\n";
        }
    }
}
