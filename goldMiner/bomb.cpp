#include "bomb.h"
#include "qpoint.h"

Bomb::Bomb(QObject *parent)
    : QObject{parent}
{
}

int Bomb::bombNum = 3;
int Bomb::bombImageTime = 0;
QPointF Bomb::bombImagePosition = QPointF(300,30);
