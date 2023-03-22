#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QUrl>

#define QUANTITY 3

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    QWidget* widget = new QWidget(this);
    setCentralWidget(widget);
    widget->setLayout(layout);

    requestField = new QLineEdit(this);
    searchButton = new QPushButton("Search", this);

    layout->addWidget(requestField);
    layout->addWidget(searchButton);

    connect(searchButton, &QPushButton::clicked, this, &MainWindow::startSearch);

    setWindowTitle("Image Search");
}

QString MainWindow::getHTML(const QString& url)
{
    QNetworkAccessManager nam;
    QNetworkReply* response = nam.get(QNetworkRequest(QUrl(url)));
    QEventLoop event;
    connect(response, &QNetworkReply::finished, &event, &QEventLoop::quit);
    event.exec();
    response->deleteLater();
    return response->readAll();
}

void MainWindow::startSearch()
{
    QString html = getHTML(searchURL + requestField->text());

    QStringList images;
    for (auto i = 0; i < QUANTITY; ++i)
        images = parse(html);

    showPics(getPics(images));
}

QStringList MainWindow::parse(const QString& html)
{
    QStringList sources;

    qsizetype pos = 0;
    for (auto i = 0; i < QUANTITY; ++i)
    {
        auto match = regexParse.match(html, pos);
        pos += match.capturedEnd(1);
        sources.append("https://" + match.captured(1));
    }

    return sources;
}

QStringList MainWindow::getPics(const QStringList& url)
{
    QStringList pics;

    for (auto& it : url)
    {
        QNetworkAccessManager nam;
        QNetworkReply* reply = nam.get(QNetworkRequest(QUrl(it)));
        QEventLoop event;
        connect(reply, &QNetworkReply::finished, &event, &QEventLoop::quit);
        event.exec();
        reply->deleteLater();

        QFile file(regexName.match(it).captured(2));
        if (file.open(QIODevice::WriteOnly))
        {
            file.write(reply->readAll());
            pics.append(file.fileName());
        }
    }

    return pics;
}

void MainWindow::showPics(const QStringList& pics)
{
    for (auto& it : pics)
    {
        QPixmap pixmap(it);
        pixmap = pixmap.scaled(pixmap.size() * 3);
        auto label = new QLabel;
        label->setPixmap(pixmap);
        label->setFixedSize(pixmap.size());
        label->show();
    }
}
