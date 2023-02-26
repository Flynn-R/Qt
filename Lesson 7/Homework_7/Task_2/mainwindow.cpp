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
            movingItem = static_cast<BlockScheme*>(block);
            movingItem->blockLeftClicked(mapToScene(event->position().toPoint()));
        }
        else
        {
            movingItem = nullptr;
            auto item = new BlockScheme(this);
            scene->addItem(item);
//            connect(this, &MainWindow::blockLeftClick, item, &BlockScheme::blockLeftClicked);
            connect(item, &BlockScheme::redraw, this, &MainWindow::redraw);
//            connect(this, &MainWindow::blockMove, item, &BlockScheme::blockMoveEvent);
//            connect(this, &MainWindow::blockRelease, item, &BlockScheme::blockReleaseEvent);
        }
    }
    else if (event->button() == Qt::RightButton)
    {
        if (block != nullptr)
        {
            delete movingItem;
            movingItem = nullptr;
            scene->removeItem(block);
        }
    }
    else if (event->button() == Qt::MiddleButton)
    {
        if (block != nullptr)
        {
            changingItem = static_cast<BlockScheme*>(block);
            changingItem->blockMiddleClicked();
        }
        else
            changingItem = nullptr;
    }
}

void MainWindow::wheelEvent(QWheelEvent* event)
{
    if (changingItem != nullptr)
    {
        changingItem->wheelMoveEvent(event->angleDelta().y());
    }
//    if (event->button() == Qt::MiddleButton)
//    {
//        if (event->angleDelta().y() > 0)
//        {
//            scene->removeItem(block);
//            auto item = new BlockScheme(this, block->getMultiplier() + 0.1);
//            scene->addItem(item);
//            connect(item, &BlockScheme::redraw, this, &MainWindow::redraw);
//        }
//        else if (event->angleDelta().y() < 0)
//        {
//            scene->removeItem(block);
//            auto item = new BlockScheme(this, block->getMultiplier() - 0.1);
//            scene->addItem(item);
//            connect(item, &BlockScheme::redraw, this, &MainWindow::redraw);
//        }
//    }
//    redraw();
}

void MainWindow::redraw()
{
    scene->update();
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && movingItem != nullptr)
    {
        movingItem->blockReleaseEvent();
        movingItem = nullptr;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (movingItem != nullptr)
        movingItem->blockMoveEvent(mapToScene(event->position().toPoint()));
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
    changing = false;
    angle = 0;
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
    emit redraw();
}

QRectF BlockScheme::boundingRect() const
{
    return QRectF(x, y, 200 * multiplier, 100 * multiplier);
}

//void BlockScheme::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
//{
//    if (event->button() == Qt::LeftButton)
//    {
//        moving = false;
//        emit redraw();
//    }
//}

//void BlockScheme::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
//{
//    if (moving)
//    {
//        this->getFigure();
//        QPoint point = event->pos().toPoint() - beginPoint;
//        x += point.x();
//        y += point.y();
//        beginPoint = event->pos().toPoint();
//        emit redraw();
//    }
//}

void BlockScheme::blockLeftClicked(QPointF point)
{
    moving = true;
    beginPointMove = point.toPoint();
}

void BlockScheme::blockMiddleClicked()
{
    changing = true;
}

void BlockScheme::blockReleaseEvent()
{
    moving = false;
    emit redraw();
}

void BlockScheme::blockMoveEvent(QPointF position)
{
    if (moving)
    {
        QPoint point = position.toPoint() - beginPointMove;
        x += point.x();
        y += point.y();
        beginPointMove = position.toPoint();
        emit redraw();
    }
}

void BlockScheme::wheelMoveEvent(qint32 angle)
{
    if (changing)
    {
        if (angle > 0)
            multiplier += 0.1;
        else if (angle < 0)
            multiplier -= 0.1;
        emit redraw();
    }
}
