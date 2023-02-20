#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void BlockScheme::setBrush(QBrush br)
{
    brush = br;
    emit redraw();
}
