#ifndef FILEVIEWER_H
#define FILEVIEWER_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QThread>
#include <QObject>
#include <QSharedPointer>

Q_PROPERTY(QStandardItemModel* model READ getCurrentModel WRITE setNewModel)

class Controller;

class FileViewer : public QWidget
{
    Q_OBJECT

public:
    explicit FileViewer(QWidget *parent = nullptr);
    void clearTree();
    QStandardItemModel* getCurrentModel() const;
    void setNewModel(QStandardItemModel*);
    void rebuildModel(QString);
    ~FileViewer() = default;

private:
    QStandardItemModel* model;
    QString currentPath;
    QString previousPath;
    QGridLayout* layout;
    QTreeView* tree;
    QPushButton* mainPath;
    QPushButton* goTo;
    QComboBox* diskSelection;
    QLineEdit* pathfinder;

    QLineEdit* search;
    QPushButton* startSearch;
    QTextEdit* info;
    Controller* controller;
    QLabel* status;

private slots:
    void changeDisk(qint32);
    void goToMainPath();
    void selectionChanged();
    void goToSelectedPath();

    void searchFiles();
    void changeStatus(QString);
    void printInfo(QString);
};

class ThreadSearch : public QThread
{
    Q_OBJECT

public:
    explicit ThreadSearch(QString, QString, QObject* parent = nullptr);
    void searchStop();

protected:
    void run() override;

private:
    QString folder;
    QString file;
    bool searching;

signals:
    void stoppedThread();
    void showFoundPath(QString);
    void searchFile(QString);
};

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller(QObject* parent = nullptr) : QObject(parent) {};
    ~Controller();
    void startSearch(QString, QString);

private:
    QSharedPointer<ThreadSearch> searchThread;
    QString currentPath;

signals:
    void changeSearchPath(QString);
    void generatePathOfFile(QString);
    void newSearch();

public slots:
    void deleteThread();
    void printCurrentPath(QString);
    void generateStringPathFile(QString);
    void finishThread();
};

#endif // FILEVIEWER_H
