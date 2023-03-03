#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QRegularExpression>
#include <QNetworkReply>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    QLineEdit* requestField;
    QPushButton* searchButton;
    const QString searchURL = "https://yandex.ru/images/search?text=";
    const QRegularExpression regexParse = QRegularExpression("<img.+?(?=src=)src=\"//(.+?(?=\"))");
    const QRegularExpression regexName = QRegularExpression("(id=)(.+?(?=-))");

    void showPics(const QStringList&);
    QString getHTML(const QString&);
    QStringList parse(const QString&);
    QStringList getPics(const QStringList&);

private slots:
    void startSearch();
};
#endif // MAINWINDOW_H
