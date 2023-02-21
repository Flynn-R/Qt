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
    QGraphicsItem* block = nullptr;
    QPointF point(mapToScene(event->position().toPoint()));
    for (auto& it : scene->items())
    {
        if (it->contains(point))
        {
            block = it;
            break;
        }
    }
    if (event->button() == Qt::LeftButton)
    {
        if (block != nullptr)
        {
            movingItem = block;
            emit blockLeftClick(mapToScene(event->position().toPoint()), movingItem);
        }
        else
        {
            movingItem = nullptr;
            auto item = new BlockScheme(this);
            scene->addItem(item);
            connect(this, &MainWindow::blockLeftClick, item, &BlockScheme::blockLeftClicked);
            connect(this, &MainWindow::blockMove, item, &BlockScheme::blockMoveEvent);
            connect(this, &MainWindow::blockRelease, item, &BlockScheme::blockReleaseEvent);
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        if (block != nullptr)
            scene->removeItem(block);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit blockRelease(movingItem);
        movingItem = nullptr;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (movingItem != nullptr)
        emit blockMove(mapToScene(event->position().toPoint()), movingItem);
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
        star << QPointF(x, y + 80 * multiplier);
        star << QPointF(x + 18 * multiplier, y + 26 * multiplier);
        star << QPointF(x + 80 * multiplier, y + 26 * multiplier);
        star << QPointF(x + 30 * multiplier, y - 10 * multiplier);
        star << QPointF(x + 50 * multiplier, y - 68 * multiplier);
        star << QPointF(x, y - 32 * multiplier);
        star << QPointF(x - 50 * multiplier, y - 68 * multiplier);
        star << QPointF(x - 30 * multiplier, y - 10 * multiplier);
        star << QPointF(x - 80 * multiplier, y + 26 * multiplier);
        star << QPointF(x - 18 * multiplier, y + 26 * multiplier);
        painter->drawPolygon(star);
    }
}

void BlockScheme::setBrush(QBrush br)
{
    brush = br;
    emit reDraw();
}

QRectF BlockScheme::boundingRect() const
{
    return QRectF(x, y, 200 * multiplier, 100 * multiplier);
}

void BlockScheme::blockLeftClicked(QPointF point, BlockScheme* block)
{
    block->beginPoint = point.toPoint();
//    moving = true;
}

void BlockScheme::blockReleaseEvent(BlockScheme* block)
{
//    moving = false;
    emit reDraw();
}

void BlockScheme::blockMoveEvent(QPointF position, BlockScheme* block)
{
//    if (moving)
//    {
        QPoint point = position.toPoint() - beginPoint;
        x += point.x();
        y += point.y();
        beginPoint = position.toPoint();
        emit reDraw();
//    }
}
