#ifndef BOMB_H
#define BOMB_H

#include <QObject>

class Bomb : public QObject
{
    Q_OBJECT
public:
    explicit Bomb(QObject *parent = nullptr);
    static int bombNum;
    static int bombImageTime;
    static QPointF bombImagePosition;
};

#endif // BOMB_H
