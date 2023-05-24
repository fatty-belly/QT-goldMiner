#include "gameobject.h"
#include "qcolor.h"
#include "QPainter"

GameObject::GameObject(Type type_, const QPointF& position_, int radius_, int score_,double hookSpeed_) :
    type(type_),
    position(position_),
    radius(radius_),
    score(score_),
    hookSpeed(hookSpeed_)
{

}

Gold::Gold(const QPointF& position_, int radius_):
    GameObject(Type::Gold, position_, radius_, radius_* 50, 5 - radius_*0.05)
{
}

void Gold::draw(QPainter& painter) const
{
    QImage goldImage("../goldMiner/Images/gold.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}

Stone::Stone(const QPointF& position_, int radius_):
    GameObject(Type::Stone, position_, radius_, radius_ * 10, 5 - radius_*0.09)
{
}

void Stone::draw(QPainter& painter) const
{
    QImage goldImage("../goldMiner/Images/stone.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}
