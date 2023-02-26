#ifndef ORGANIZER_H
#define ORGANIZER_H

#include <QObject>
#include <QFile>
#include <QDate>

class Organizer : public QObject
{
    Q_OBJECT

public:
    explicit Organizer(QObject *parent = nullptr);
    ~Organizer();
    Q_INVOKABLE void addNewTask(QString, QString, QString);
    Q_INVOKABLE void writeToFile();

private:
    QFile* file;
    QStringList taskList;

signals:
    void fileLoaded(bool success);
};

#endif // ORGANIZER_H
