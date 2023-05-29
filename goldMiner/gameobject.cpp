#include "gameobject.h"
#include "qcolor.h"
#include "QPainter"

GameObject::GameObject(Type type_, const QPointF& position_, int radius_, int score_,double hookSpeed_, int timeplus_ = 0) :
    type(type_),
    position(position_),
    radius(radius_),
    score(score_),
    hookSpeed(hookSpeed_),
    timeplus(timeplus_)
{

}

Gold::Gold(const QPointF& position_, int radius_):
    GameObject(Type::Gold, position_, radius_, radius_* 50, 5 - radius_*0.05)
{
}

void Gold::draw(QPainter& painter) const
{
    QImage goldImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/gold.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}

Stone::Stone(const QPointF& position_, int radius_):
    GameObject(Type::Stone, position_, radius_, radius_ * 10, 5 - radius_*0.09)
{
}

void Stone::draw(QPainter& painter) const
{
    QImage goldImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/stone.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}


Diamond::Diamond(const QPointF &position_, int radius_):
    GameObject(Type::Diamond,position_,radius_,radius_ * 20,5 + radius_ * 0.09)
{
}

void Diamond::draw(QPainter &painter) const{
    QImage goldImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/diamond.png");
    goldImage = goldImage.scaled(1*radius,1*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}


TimePlus::TimePlus(const QPointF &position_, int radius_):
    GameObject(Type::TimePlus,position_,radius_,0,5 + radius_ * 0.09, 10)
{
}

void TimePlus::draw(QPainter &painter) const{
    QImage goldImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/time.png");
    goldImage = goldImage.scaled(4*radius,4*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}

Bag::Bag(const QPointF &position_, int radius_):
    GameObject(Type::Bag,position_,radius_,0,5 + radius_ * 0.09)
{
}

void Bag::draw(QPainter &painter) const{
    QImage goldImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/bag.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}
