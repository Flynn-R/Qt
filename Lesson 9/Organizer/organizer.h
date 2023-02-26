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
    Q_INVOKABLE void writeNewTask(QString, QString, QString);

private:
    QFile* file;

signals:
    void fileLoaded(bool success);
};

#endif // ORGANIZER_H
