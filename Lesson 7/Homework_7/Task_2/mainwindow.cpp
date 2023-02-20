#include "mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView{parent}
{
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        auto item = new BlockScheme(this);
        scene->addItem(item);
        connect(item, &BlockScheme::deleteBlock, this, &MainWindow::deleteBlock);
    }
}

void MainWindow::deleteBlock(BlockScheme* item)
{
    scene->removeItem(item);
}

BlockScheme::BlockScheme(QObject* parent, double multi) : QObject(parent), QGraphicsItem(), x(0), y(0), multiplier(multi)
{
    srand(clock());
    brush.setColor(QColor(rand() % 256, rand() % 256, rand() % 256));
    brush.setStyle(Qt::SolidPattern);
    if (figureNext == RECTANGLE)
    {
        figure = RECTANGLE;
        figureNext = ELLIPSE;
    }
    else if (figureNext == ELLIPSE)
    {
        figure = ELLIPSE;
        figureNext = STAR;
    }
    else
    {
        figure = STAR;
        figureNext = RECTANGLE;
    }
    setPos(x, y);
    moving = false;
}

void BlockScheme::paint(QPainter* painter, const QStyleOptionGraphicsItem* options, QWidget* widget)
{
    Q_UNUSED(options)
    Q_UNUSED(widget)
    painter->setBrush(brush);
    if (figure == RECTANGLE)
        painter->drawRect(x, y, 200 * multiplier, 100 * multiplier);
    else if (figure == ELLIPSE)
        painter->drawEllipse(x, y, 200 * multiplier, 100 * multiplier);
    else
    {
        QPolygonF star;
        star << QPointF(x - 18 * multiplier, y + 26 * multiplier);
        star << QPointF(x - 80 * multiplier, y + 26 * multiplier);
        star << QPointF(x - 30 * multiplier, y - 10 * multiplier);
        star << QPointF(x - 50 * multiplier, y - 68 * multiplier);
        star << QPointF(x, y - 32 * multiplier);
        star << QPointF(x + 50 * multiplier, y - 65 * multiplier);
        star << QPointF(x + 30 * multiplier, y - 10 * multiplier);
        star << QPointF(x + 80 * multiplier, y + 26 * multiplier);
        star << QPointF(QPointF(x + 18 * multiplier, y + 26 * multiplier));
        star << QPointF(x, y + 80 * multiplier);
        painter->drawPolygon(star);
    }
}

void BlockScheme::setBrush(QBrush br)
{
    brush = br;
    emit redraw();
}

QRectF BlockScheme::boundingRect() const
{
    return QRectF(x, y, 200 * multiplier, 100 * multiplier);
}

void BlockScheme::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    if (event->button() == Qt::RightButton)
        emit deleteBlock(this);
}
