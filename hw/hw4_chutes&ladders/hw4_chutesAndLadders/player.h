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
    Player(QGraphicsItem *parent = nullptr);


    int getX();
    int getY();

    void setX(int x);
    void setY(int y);

    void setPrevValue(int prevValue);
    int getPrevValue();

    void setCurrValue(int currValue);
    int getCurrValue();

    void setName(QString name) {name_ = name;}
    QString getName(){
        return name_;
    }

    void useUndo();
    void setUndo(int u){undoCount_ = u;}
    int getUndoCount();

    void useReroll();
    void setReroll(int rr){rerollCount_ = rr;}
    int getRerollCount();

    void useRoll();
    void setRollCount(int rollCount) {rollCount_ = rollCount;}
    int getRollCount();

    void setOnBoard(){
        onBoard_ = !onBoard_;
    }

    void writeOnBoard(int ob){
        onBoard_ = ob;
    }

    bool getOnboard_(){
        return onBoard_;
    }

    void setDiameter(int d) {diameter_= d;}
    int getDiameter(){return diameter_;}

    void setColor(int c){color_ = c;}
    int getColor(){return color_;}

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
    bool onBoard_;

signals:

};

#endif // PLAYER_H
