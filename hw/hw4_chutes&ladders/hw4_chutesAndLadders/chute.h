#ifndef CHUTE_H
#define CHUTE_H

#include <QObject>
#include <QGraphicsLineItem>

class Chute : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    Chute(int start, int end, QObject *parent = nullptr);
    Chute(QObject *parent = nullptr);
    ~Chute() override;

    int getStart() const;
    void setStart(int s){start_=s;}

    int getEnd() const;
    void setEnd(int e){end_=e;}


private:
    int start_;
    int end_;
    void setupChute();
};

#endif // CHUTE_H
