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

protected:
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;

signals:
    void blockLeftClick(QPointF, BlockScheme*);
    void blockMove(QPointF, BlockScheme*);
    void blockRelease(BlockScheme*);
};

class BlockScheme : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit BlockScheme(QObject* parent = nullptr, double multi = 1.0);
    void setBrush(QBrush);

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
    QBrush brush;
    double multiplier;
    QPoint beginPoint;

signals:
    void reDraw();

public slots:
    void blockLeftClicked(QPointF, BlockScheme*);
    void blockMoveEvent(QPointF, BlockScheme*);
    void blockReleaseEvent(BlockScheme*);
};

#endif // MAINWINDOW_H
