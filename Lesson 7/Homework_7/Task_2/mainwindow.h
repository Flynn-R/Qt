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

private slots:
    void addBlock(BlockScheme*);

protected:
    void mousePressEvent(QMouseEvent*) override;
};

class BlockScheme : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    explicit BlockScheme(QPoint, QObject* parent = nullptr, double multi = 1.0);
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
    QPoint beginPoint;
    bool moving;
    QBrush brush;
    double multiplier;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override;
//    void mouseMoveEvent(QGraphicsSceneMouseEvent*) override;

signals:
    void redraw();
    void addBlock(QGraphicsSceneMouseEvent*);
    void deleteBlock();
};

#endif // MAINWINDOW_H
