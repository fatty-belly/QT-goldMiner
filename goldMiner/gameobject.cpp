#include "gameobject.h"
#include "qcolor.h"
#include "QPainter"
#include <random>
using namespace std;

GameObject::GameObject(Type type_, const QPointF& position_, int radius_, int score_,double hookSpeed_, int timeplus_ = 0, int bombplus_ = 0) :
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
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}


BombPlus::BombPlus(const QPointF &position_, int radius_):
    GameObject(Type::BombPlus,position_,radius_, 0, 5 + radius_ * 0.09, 0, 2)
{
}

void BombPlus::draw(QPainter &painter) const{
    QImage goldImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/bomb.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}


Bag::Bag(const QPointF &position_, int radius_):
    GameObject(Type::Bag,position_,radius_,0,5 + radius_ * 0.09)
{
    random_device rd;
    mt19937 gen(rd());

    // 创建随机数分布
    uniform_int_distribution<int> dis(0, 3);

    // 生成随机数
    int randomNum = dis(gen);

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
        hookSpeed = 5 + radius_ * 0.09;
        timeplus = 10;
    }
    else if (randomNum == 3){
        type = BombPlus;
        score = 0;
        hookSpeed = 5 + radius_ * 0.09;
        bombplus = 2;
    }
}

void Bag::draw(QPainter &painter) const{
    QImage goldImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/bag.png");
    goldImage = goldImage.scaled(2*radius,2*radius);
    painter.drawImage(position-QPointF(radius,radius),goldImage);
}
