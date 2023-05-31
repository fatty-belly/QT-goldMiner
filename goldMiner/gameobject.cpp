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
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/gold.png");
    image = image.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),image);
}

Stone::Stone(const QPointF& position_, int radius_):
    GameObject(Type::Stone, position_, radius_, radius_ * 10, 5 - radius_*0.09)
{
}

void Stone::draw(QPainter& painter) const
{
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/stone.png");
    image = image.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),image);
}


Diamond::Diamond(const QPointF &position_, int radius_):
    GameObject(Type::Diamond,position_, radius_, radius_ * radius_ * 25, 5)
{
}

void Diamond::draw(QPainter &painter) const{
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/diamond.png");
    image = image.scaled(2*radius, 2*radius);
    painter.drawImage(position - QPointF(radius,radius),image);
}

TimePlus::TimePlus(const QPointF &position_, int radius_, bool shortTime):
    GameObject(Type::TimePlus, position_, radius_, 1, 5, 15, 0)
{
    if(shortTime)
        timeplus = 8;
}

void TimePlus::draw(QPainter &painter) const{
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/time.png");
    image = image.scaled(2*radius,2*radius);
    painter.drawImage(position - QPointF(radius,radius),image);
}

BombPlus::BombPlus(const QPointF &position_, int radius_):
    GameObject(Type::BombPlus,position_,radius_, 0, 5, 0, 1)
{
}

void BombPlus::draw(QPainter &painter) const{
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/TNT.png");
    image = image.scaled(2*radius,2.4*radius);
    painter.drawImage(position-QPointF(radius,radius),image);
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
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/bag.png");
    image = image.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),image);
}


StrengthUp::StrengthUp(const QPointF &position_, int radius_):
    GameObject(Type::StrengthUp,position_,radius_,0,5)
{
}

void StrengthUp::draw(QPainter &painter) const{
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/+.png");
    image = image.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),image);
}

StrengthDown::StrengthDown(const QPointF &position_, int radius_):
    GameObject(Type::StrengthDown,position_,radius_,0,5)
{
}

void StrengthDown::draw(QPainter &painter) const{
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/-.png");
    image = image.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),image);
}

TNT::TNT(const QPointF &position_, int radius_):
    GameObject(Type::TNT,position_,radius_,0,5)
{
}

void TNT::draw(QPainter &painter) const{
    QImage image("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/realbomb.png");
    image = image.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),image);
}
