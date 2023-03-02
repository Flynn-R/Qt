#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include "downloader.h"
#include "imagegetter.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    Downloader downloader;
    QLineEdit* requestField;
    QPushButton* searchButton;
    const QString searchURL = "https://yandex.ru/images/search?text=";
    QFile* html;

    void showPics(QStringList);

private slots:
    void startSearch();
    void finishSearch(const QUrl&, const QByteArray&);
};
#endif // MAINWINDOW_H
