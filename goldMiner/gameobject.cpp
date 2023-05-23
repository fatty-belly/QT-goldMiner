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
    QColor goldColor(212,175,55);
    painter.setBrush(goldColor);
    painter.drawEllipse(position, radius, radius);
}

Stone::Stone(const QPointF& position_, int radius_):
    GameObject(Type::Stone, position_, radius_, radius_ * 10, 5 - radius_*0.09)
{
}

void Stone::draw(QPainter& painter) const
{
    QColor grayColor(128,128,128);
    painter.setBrush(grayColor);
    painter.drawEllipse(position, radius, radius);
}
