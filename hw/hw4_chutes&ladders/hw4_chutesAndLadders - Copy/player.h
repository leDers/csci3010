#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>

#include <QObject>
#include <QGraphicsEllipseItem>

class Player : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    Player(int x, int y, int currValue, int diameter, QString name, int color, QGraphicsItem *parent = nullptr);
    Player(int x, int y, int currValue, int diameter, QGraphicsItem *parent = nullptr);


    int getX();
    int getY();

    void setX(int x);
    void setY(int y);

    void setPrevValue(int prevValue);
    int getPrevValue();

    void setCurrValue(int currValue);
    int getCurrValue();

    QString getName(){
        return name_;
    }

    void useUndo();
    int getUndoCount();

    void useReroll();
    int getRerollCount();

    void useRoll();
    int getRollCount();


private:
    int x_;
    int y_;
    int prevValue_;
    int currValue_;
    int diameter_;
    int color_;

    int undoCount_;
    int rerollCount_;

    int rollCount_;

    QString name_;

signals:

};

#endif // PLAYER_H
