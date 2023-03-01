#include "organizer.h"
//#include <QTextStream>
#include <QSqlQuery>

Organizer::Organizer(QObject *parent)
    : QObject{parent}
{
//    file = new QFile("../Organizer/tasks.txt");
    database = QSqlDatabase::addDatabase("QSQLITE");
//    database.setDatabaseName(":/tasks.db");   Почему-то не работает
    database.setDatabaseName("../Organizer/tasks.db");
    database.open();
}

Organizer::~Organizer()
{
    if (database.isOpen())
        database.close();
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
                taskList.append(new Task(name, d, progress.toInt()));
                return;
            }
        }
    }

    emit incorrectData();
}

void Organizer::writeToFile()
{
    QSqlQuery query(database);
    if (database.isOpen())
        query.exec("CREATE TABLE IF NOT EXISTS \"Tasks\" (\"name\" VARCHAR(32) NOT NULL, \"deadline\" DATE NOT NULL, \"progress\" INT NOT NULL)");
    else
    {
        emit fileLoaded(false);
        return;
    }

    if (!taskList.isEmpty())
    {
//        QTextStream stream(file);
        for (auto& it : taskList)
            query.exec(QString("INSERT INTO \"Tasks\" (\"name\", \"deadline\", \"progress\") VALUES (\"%1\", \"%2\", %3)").arg(it->name).arg(it->deadline.toString("yyyy-MM-dd")).arg(it->progress));
    }
}

QString Organizer::currentStatus()
{
//    if (file->open(QIODevice::ReadOnly))
//        emit fileLoaded(true);
//    else
//        emit fileLoaded(false);

    if (database.isOpen())
    {
        QSqlQuery query(database);
        query.exec("SELECT COUNT (*) FROM Tasks");

        qint32 recent = taskList.count();
        qint32 total = (query.next() ? recent + query.value(0).toInt() : recent);

        return "Recently added: " + QString::number(recent) + ". Total: " + QString::number(total);
    }
    else
        emit fileLoaded(false);
    return "";
}

void Organizer::tasksView()
{
    if (database.isOpen())
    {
        model = new QSqlTableModel(this, database);
        emit setModel(*model);
//        Table table(database);
//        table.show();
    }
}
