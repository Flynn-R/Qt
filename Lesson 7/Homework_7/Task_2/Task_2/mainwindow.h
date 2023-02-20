#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>

class MainWindow : public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QGraphicsView* view;
    QGraphicsScene* scene;

signals:

};

class BlockScheme : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit BlockScheme(QObject* parent = nullptr);
    void setBrush(QBrush);

private:
    void paint(QPainter*);

};

#endif // MAINWINDOW_H
