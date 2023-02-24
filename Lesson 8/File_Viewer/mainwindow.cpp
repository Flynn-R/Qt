#include "mainwindow.h"
#include "fileviewer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setCentralWidget(new FileViewer(this));
}
