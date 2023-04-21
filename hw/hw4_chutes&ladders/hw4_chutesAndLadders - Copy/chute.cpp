#include "chute.h"

#include <QPen>

Chute::Chute(int start, int end, QObject *parent)
    : QObject(parent),
      start_(start), end_(end)
{
    setupChute();
}

Chute::~Chute()
{
    // empty
}

int Chute::getStart() const
{
    return start_;
}

int Chute::getEnd() const
{
    return end_;
}

void Chute::setupChute()
{
    // Set the pen for the line
    QPen pen(Qt::red);
    pen.setWidth(5);
    setPen(pen);
}
