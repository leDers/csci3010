#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPen>

#include "chute.h"

class Tile : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Tile(int value, int x, int y, int wh, QGraphicsItem *parent = nullptr);
    ~Tile() override;

    int getValue() const;
    int getX() const;
    int getY() const;
    int getWH() const;

    void setChute(Chute *c);
    Chute* getChute();

    bool checkChute();

private:
    int value_;
    int x_;
    int y_;
    int wh_;
    QGraphicsTextItem *text_;
    QGraphicsRectItem *rect_;

    bool hasChute_;
    Chute *tileChute_;
\
    void setupTile();
};

#endif // TILE_H
