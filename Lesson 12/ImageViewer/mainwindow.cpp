#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QLabel>
#include "imagegetter.h"

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
    connect(&downloader, &Downloader::finished, this, &MainWindow::finishSearch);
}

void MainWindow::startSearch()
{
    downloader.download(QUrl(searchURL + requestField->text()));
}

void MainWindow::finishSearch(const QUrl& url, const QByteArray& bArray)
{
    html = new QFile(url.path().section('/', -1));
    if (html->open(QIODevice::ReadWrite))
        html->write(bArray);

    ImageGetter imageGetter(html);
    showPics(imageGetter.getImages());
    if (html->isOpen())
        html->close();
}

void MainWindow::showPics(QStringList pics)
{
    for (auto& it : pics)
    {
        auto label = new QLabel;
        label->setPixmap(QPixmap(it));
        label->setFixedSize(label->pixmap().size());
        label->show();
    }
}
