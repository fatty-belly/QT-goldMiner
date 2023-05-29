#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "qpoint.h"
#include "qwindowdefs.h"
#include <QObject>

class GameObject : public QObject
{
    Q_OBJECT
public:
    enum Type {
        Stone,
        Gold,
        Diamond,
        TimePlus,
        Bag,
        // 其他物体类型
    };
    GameObject(Type type_, const QPointF& position_, int radius_, int score_,double hookSpeed_,int timeplus_);
    virtual void draw(QPainter& painter) const = 0;
    Type type;
    QPointF position;
    int radius;
    int score;
    double hookSpeed;//抓取到物体后抓钩的速度
    int timeplus;
};

class Gold: public GameObject
{
public:
    Gold(const QPointF& position_, int radius_);
    void draw(QPainter& painter) const override;
};

class Stone: public GameObject
{
public:
    Stone(const QPointF& position_, int radius_);
    void draw(QPainter& painter) const override;
};

class Diamond: public GameObject{
public:
    Diamond(const QPointF& position_, int radius_);
    void draw(QPainter& painter) const override;
};

class TimePlus: public GameObject{
public:
    TimePlus(const QPointF& position_, int radius_);
    void draw(QPainter& painter) const override;
};


class Bag: public GameObject{
public:
    Bag(const QPointF& position_, int radius_);
    void draw(QPainter& painter) const override;
};



#endif // GAMEOBJECT_H
