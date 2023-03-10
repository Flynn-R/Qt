#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QObject>
#include <QFile>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QTableView>

class Organizer : public QObject
{
    Q_OBJECT

public:
    explicit Organizer(QObject *parent = nullptr);
    ~Organizer();
    Q_INVOKABLE void addNewTask(QString, QString, QString);
    Q_INVOKABLE void writeToFile();
    Q_INVOKABLE QString currentStatus();
    Q_INVOKABLE void tasksView();

private:
//    QFile* file;
    struct Task
    {
        QString name;
        QDate deadline;
        qint8 progress;

        Task(QString n, QDate d, qint8 p) : name(n), deadline(d), progress(p) {}
    };
    QList<Task*> taskList;
    QSqlDatabase database;
    QSqlTableModel* model;

signals:
    void fileLoaded(bool success);
    void incorrectData();
    void setModel(QSqlTableModel& mdl);
};

#endif // ORGANIZER_H
