#include "gameobject.h"
#include "QPainter"
#include <QRandomGenerator>

GameObject::GameObject(Type type_, const QPointF& position_, int radius_, int score_,double hookSpeed_, int timeplus_, int bombplus_) :
    type(type_),
    position(position_),
    radius(radius_),
    score(score_),
    hookSpeed(hookSpeed_),
    timeplus(timeplus_),
    bombplus(bombplus_)
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


Diamond::Diamond(const QPointF &position_, int radius_):
    GameObject(Type::Diamond,position_, radius_, radius_ * radius_ * 25, 5)
{
}

void Diamond::draw(QPainter &painter) const{
    QImage goldImage("../goldMiner/Images/diamond.png");
    goldImage = goldImage.scaled(2*radius, 2*radius);
    painter.drawImage(position - QPointF(radius,radius),goldImage);
}

TimePlus::TimePlus(const QPointF &position_, int radius_, bool shortTime):
    GameObject(Type::TimePlus, position_, radius_, 1, 5, 15, 0)
{
    if(shortTime)
        timeplus = 8;
}

void TimePlus::draw(QPainter &painter) const{
    QImage goldImage("../goldMiner/Images/time.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position - QPointF(radius,radius),goldImage);
}

BombPlus::BombPlus(const QPointF &position_, int radius_):
    GameObject(Type::BombPlus,position_,radius_, 0, 5, 0, 2)
{
}

void BombPlus::draw(QPainter &painter) const{
    QImage goldImage("../goldMiner/Images/realBomb.png");
    goldImage = goldImage.scaled(2*radius,2.4*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}


Bag::Bag(const QPointF &position_, int radius_):
    GameObject(Type::Bag, position_, radius_, 0 , 5)
{
    int randomNum = QRandomGenerator::global()->bounded(0, 4);

    if (randomNum == 0){
        type = Gold;
        score = radius_* 50;
        hookSpeed = 5 - radius_*0.05;
    }
    else if (randomNum == 1)
    {
        type = Stone;
        score = radius_ * 10;
        hookSpeed = 5 - radius_*0.09;
    }
    else if (randomNum == 2){
        type = TimePlus;
        score = 0;
        hookSpeed = 5;
        timeplus = 15;
    }
    else if(randomNum == 3)
    {
        type = BombPlus;
        score = 0;
        hookSpeed = 5;
        bombplus = 2;
    }
}

void Bag::draw(QPainter &painter) const{
    QImage goldImage("../goldMiner/Images/bag.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}


Strengup::Strengup(const QPointF &position_, int radius_):
    GameObject(Type::Strengup,position_,radius_,0,5 + radius_ * 0.09)
{
}

void Strengup::draw(QPainter &painter) const{
    QImage goldImage("D:/courses/c++/QT-goldMiner/goldMiner/Images/+.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}

Strengdown::Strengdown(const QPointF &position_, int radius_):
    GameObject(Type::Strengdown,position_,radius_,0,5 + radius_ * 0.09)
{
}

void Strengdown::draw(QPainter &painter) const{
    QImage goldImage("D:/courses/c++/QT-goldMiner/goldMiner/Images/-.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}
