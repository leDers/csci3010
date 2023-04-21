#include "tile.h"

Tile::Tile(int value, int x, int y, int wh,  QGraphicsItem *parent)
    : QObject(), QGraphicsRectItem(parent), value_(value), x_(x), y_(y), wh_(wh), text_(nullptr), rect_(nullptr), tileChute_(nullptr)
{
    setupTile();
}

Tile::~Tile()
{
    delete text_;
}

int Tile::getValue() const
{
    return value_;
}

int Tile::getX() const
{
    return x_;
}

int Tile::getY() const
{
    return y_;
}

void Tile::setChute(Chute *c){
    tileChute_ = c;
    hasChute_ = true;
}

Chute* Tile::getChute(){
    return tileChute_;
}

bool Tile::checkChute(){
    return hasChute_;
}

void Tile::setupTile()
{
    // Set the size and position of the tile
    // Set the tile's size and position
    rect_= new QGraphicsRectItem(x_, y_, wh_, wh_, this);
    rect_->setPen(QPen(Qt::black));
    rect_->setBrush(QBrush(Qt::white));
    if ((x_%2==0 && y_%2!=0) || (x_%2!=0 && y_%2==0)){
        rect_->setBrush(QBrush(Qt::gray));
    }

    // Add text to the tile
    text_ = new QGraphicsTextItem(QString::number(value_), this);
    text_->setPos(x_ + wh_/2 - text_->boundingRect().width()/2, y_ + wh_/2 - text_->boundingRect().height()/2);
    text_->setDefaultTextColor(Qt::black);

    hasChute_ = false;
}
