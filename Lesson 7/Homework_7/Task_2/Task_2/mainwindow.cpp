#include "mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView{parent}
{
    scene = new QGraphicsScene(this);
    setScene(scene);
}

void MainWindow::addBlock(BlockScheme* item)
{
    scene->addItem(item);
    connect(item, &BlockScheme::addBlock, this, &MainWindow::addBlock);
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    auto item = new BlockScheme(event->position().toPoint(), this);
    addBlock(item);
}

BlockScheme::BlockScheme(QPoint pos, QObject* parent, double multi) : QObject(parent), QGraphicsItem(), x(pos.x()), y(pos.y()), multiplier(multi)
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
        QList<QPointF> poly;
        poly.append(QPointF(x, 80 * multiplier));
        poly.append(QPointF(x + 18 * multiplier, y + 26 * multiplier));
        poly.append(QPointF(x + 80 * multiplier, y + 26 * multiplier));
        poly.append(QPointF(x + 30 * multiplier, y - 10 * multiplier));
        poly.append(QPointF(x + 50 * multiplier, y - 65 * multiplier));
        poly.append(QPointF(x, y - 32 * multiplier));
        poly.append(QPointF(x - 50 * multiplier, y - 68 * multiplier));
        poly.append(QPointF(x - 30 * multiplier, y - 10 * multiplier));
        poly.append(QPointF(x - 80 * multiplier, y + 26 * multiplier));
        poly.append(QPointF(x - 18 * multiplier, y + 26 * multiplier));
        QPolygonF star(poly);
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
        emit deleteBlock();
    if (event->button() == Qt::LeftButton)
        emit addBlock(event);
}
