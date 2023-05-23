#ifndef BOMB_H
#define BOMB_H

#include <QObject>

class Bomb : public QObject
{
    Q_OBJECT
public:
    explicit Bomb(QObject *parent = nullptr);
    static int bombNum;//炸药的数量
    static int bombImageTime;//炸药特效持续时间(s)
    static QPointF bombImagePosition;//炸药特效显示的位置
};

#endif // BOMB_H
