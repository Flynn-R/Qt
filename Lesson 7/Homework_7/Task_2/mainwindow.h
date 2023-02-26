#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class BlockScheme;

class MainWindow : public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() = default;

private:
    QGraphicsView* view;
    QGraphicsScene* scene;
    BlockScheme* movingItem;
    BlockScheme* changingItem;

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void wheelEvent(QWheelEvent*) override;

signals:
//    void blockLeftClick(QPoint);
//    void blockMove(QPointF, BlockScheme*);
//    void blockRelease(BlockScheme*);

private slots:
    void redraw();
};

class BlockScheme : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit BlockScheme(QObject* parent = nullptr, double multi = 1.0);
    void setBrush(QBrush);
    void blockLeftClicked(QPointF);
    void blockMiddleClicked();
    void blockMoveEvent(QPointF);
    void blockReleaseEvent();
    void wheelMoveEvent(qint32);

private:
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    QRectF boundingRect() const override;
    qint32 x, y;
    enum Geometry
    {
        RECTANGLE, ELLIPSE, STAR
    };
    static Geometry figureNext;
    Geometry figure;
    bool moving;
    bool changing;
    qint32 angle;
    QBrush brush;
    double multiplier;
    QPoint beginPointMove;

signals:
    void redraw();

protected:
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;

//public slots:
//    void blockLeftClicked(QPoint);
//    void blockMoveEvent(QPointF, BlockScheme*);
//    void blockReleaseEvent(BlockScheme*);
};

#endif // MAINWINDOW_H
