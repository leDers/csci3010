#ifndef CHUTE_H
#define CHUTE_H

#include <QObject>
#include <QGraphicsLineItem>

class Chute : public QObject, public QGraphicsLineItem
{
    Q_OBJECT
public:
    Chute(int start, int end, QObject *parent = nullptr);
    ~Chute() override;

    int getStart() const;
    int getEnd() const;


private:
    int start_;
    int end_;
    void setupChute();
};

#endif // CHUTE_H
