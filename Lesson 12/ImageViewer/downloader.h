#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);
    void download(const QUrl&);

signals:
    void finished(const QUrl&, const QByteArray&);

private slots:
    void downloadComplete(QNetworkReply*);

private:
    QNetworkAccessManager nam;
};

#endif // DOWNLOADER_H
