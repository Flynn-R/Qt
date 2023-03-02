#ifndef IMAGEGETTER_H
#define IMAGEGETTER_H

#include <QObject>
#include <QFile>
#include "downloader.h"

class ImageGetter : public QObject
{
    Q_OBJECT
public:
    explicit ImageGetter(QFile*, QObject *parent = nullptr);
    QStringList getImages();

private:
    QString html;
    QStringList sources;
    QStringList images;
    Downloader downloader;
    bool imagesReady;

private slots:
    void finished(const QUrl&, const QByteArray&);
};

#endif // IMAGEGETTER_H
