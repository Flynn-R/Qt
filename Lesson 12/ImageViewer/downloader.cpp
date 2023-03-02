#include "downloader.h"
#include <QNetworkReply>

Downloader::Downloader(QObject *parent)
    : QObject{parent}
{
    connect(&nam, &QNetworkAccessManager::finished, this, &Downloader::downloadComplete);
}

void Downloader::download(const QUrl& url)
{
    nam.get(QNetworkRequest(url));
}

void Downloader::downloadComplete(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NetworkError::NoError)
        emit finished(reply->url(), reply->readAll());
    reply->deleteLater();
}
