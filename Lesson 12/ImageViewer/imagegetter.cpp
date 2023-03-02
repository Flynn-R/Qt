#include "imagegetter.h"
#include <QTextStream>

#define QUANTITY 3

ImageGetter::ImageGetter(QFile* file, QObject *parent)
    : QObject{parent}
{
    imagesReady = false;
    QTextStream stream(file);
    html = stream.readAll();

    qint64 pos;
    for (auto i = 0; i < QUANTITY; ++i)
    {
        pos = html.indexOf("<img");
        if (pos > 0)
        {
            qint64 startSrcPos = html.indexOf("src=\"", pos) + 5;
            qint64 endSrcPos = html.indexOf('"', startSrcPos + 1);
            sources.append(html.mid(startSrcPos, endSrcPos - startSrcPos));
            pos += endSrcPos;
            qDebug() << html.mid(startSrcPos - 25, endSrcPos - startSrcPos + 25);
        }
    }

    connect(&downloader, &Downloader::finished, this, &ImageGetter::finished);

    for (auto& it : sources)
        downloader.download(it);
}

QStringList ImageGetter::getImages()
{
    while (!imagesReady)
    return images;
}

void ImageGetter::finished(const QUrl& url, const QByteArray& bArray)
{
    QFile file(url.path().section('/', -1));
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(bArray);
        file.close();
    }

    images.append(file.fileName());
    if (images.count() == QUANTITY)
        imagesReady = true;
}
