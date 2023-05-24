#include "gameobject.h"
#include "qcolor.h"
#include "QPainter"
#include "QPixmap"

GameObject::GameObject(Type type_, const QPointF& position_, QPixmap objectPixmap_, int radius_, int score_,double hookSpeed_) :
    type(type_),
    position(position_),
    objectPixmap(objectPixmap_),
    radius(radius_),
    score(score_),
    hookSpeed(hookSpeed_)
{

}

BigGold::BigGold(const QPointF& position_):
    GameObject(Type::Gold, position_, QPixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/big.png"), 5, 500, 3)
{
}

SmallGold::SmallGold(const QPointF& position_):
    GameObject(Type::Gold, position_, QPixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/small.png"), 3, 200, 4)
{
}

void BigGold::draw(QPainter& painter) const
{
    painter.drawPixmap(position,objectPixmap);
}

void SmallGold::draw(QPainter& painter) const
{
    painter.drawPixmap(position,objectPixmap);
}

Stone::Stone(const QPointF& position_):
    GameObject(Type::Stone, position_, QPixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/stone.png"), 5, 10, 1)
{
}

void Stone::draw(QPainter& painter) const
{
       painter.drawPixmap(position,objectPixmap);
}
