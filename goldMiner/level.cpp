#include "level.h"
#include "endgamedialog.h"
#include "hook.h"
#include "bomb.h"
#include "ui_level.h"
#include "gameobject.h"
#include <QKeyEvent>
#include <QRandomGenerator>
#include <QPainter>
#include <QTime>

int Level::totalLevelNum = 4;

Level::Level(QWidget *parent, int levelNum_) :
    QWidget(parent),
    score(0),
    ui(new Ui::Level),
    minerPixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/goldminer.png"),
    restTime(90),
    levelNum(levelNum_)
{
    ui->setupUi(this);
    ui->minerLabel->setPixmap(minerPixmap);
    gameObjects.clear();
    hook = new Hook(ui, this);
    QTimer *gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level::updateTimer);
    gameTimer->start(1000);
    switch(levelNum)
    {
    case 1:
//        generateRandomObjects(8,12);//第一关-正常关
        generateBags(5);//神秘背包
        goalScore = 7500;
        Bomb::bombNum = 5;
        break;
    case 2:
        generateRandomObjects(10,10);//第二关-正常关

        goalScore = 9000;
        break;
    case 3:
        generateRandomObjects(25,5,true);
        Bomb::bombNum += 5;//第三关-碎石关
        goalScore = 6000;
        break;
    case 4:
        generateSpecialObjects(5);//第四关-雪花关
        goalScore = 7000;
        break;
    }
    ui->goalScoreLabel->setText(QString("目标分数:%1").arg(goalScore));
    update();
}

void Level::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Down)
    {
        hook->extend();//按↓键伸钩子
    }
    if(event->key() == Qt::Key_Up)
    {
        hook->bomb();//按↑键扔炸药
    }
}

void Level::generateRandomObjects(int numStones,int numGolds, int special)
{
    while(numStones > 0 || numGolds > 0)
    {
        bool flag = false;
        int x,y,radius;
        if((!special && QRandomGenerator::global()->bounded(0, numStones + numGolds) < numStones)
            || numGolds == 0)
        {
            while(!flag)
            {
                flag=true;
                x = QRandomGenerator::global()->bounded(0, 600);
                y = QRandomGenerator::global()->bounded(150, 300); // 石头在比较上面
                radius = QRandomGenerator::global()->bounded(10, 50);
                for(GameObject* object:gameObjects)
                {
                    if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < radius + object->radius)
                    {
                        flag = false;
                        break;
                    }
                }
            }//碰撞检测
            gameObjects.push_back(new Stone(QPoint(x, y), radius));
            numStones--;
        }
        else
        {
            while(!flag)
            {
                flag=true;
                x = QRandomGenerator::global()->bounded(0, 600);
                y = QRandomGenerator::global()->bounded(200, 350); // 金块在比较下面
                if(special)
                    radius = QRandomGenerator::global()->bounded(28, 33);
                else
                    radius = QRandomGenerator::global()->bounded(20, 40);
                for(GameObject* object:gameObjects)
                {
                    if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < radius + object->radius)
                    {
                        flag = false;
                        break;
                    }
                }
            }//碰撞检测
            gameObjects.push_back(new Gold(QPoint(x, y), radius));
            numGolds--;
        }
    } // 在随机位置产生随机半径的石头与金块
}

void Level::generateSpecialObjects(int numGolds)
{
    for (int i = 1; i <= numGolds; i++)
    {
        int x,y,radius;
        bool flag = false;
        while(!flag)
        {
            flag=true;
            x = QRandomGenerator::global()->bounded(0, 600);
            y = QRandomGenerator::global()->bounded(150, 350); // 石头在比较上面
            radius = QRandomGenerator::global()->bounded(25, 35);
            for(GameObject* object:gameObjects)
            {
                if(object->type == GameObject::Type::Stone)
                    continue;
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < 2*(radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        gameObjects.push_back(new Gold(QPoint(x, y), radius));
        gameObjects.push_back(new Stone(QPoint(x - 2 * radius, y), radius/2));
        gameObjects.push_back(new Stone(QPoint(x + 2 * radius, y), radius/2));
        gameObjects.push_back(
            new Stone(QPoint(x - radius, y - sqrt(3) * radius), radius/2));
        gameObjects.push_back(
            new Stone(QPoint(x + radius, y - sqrt(3) * radius), radius/2));
        gameObjects.push_back(
            new Stone(QPoint(x - radius, y + sqrt(3) * radius), radius/2));
        gameObjects.push_back(
            new Stone(QPoint(x + radius, y + sqrt(3) * radius), radius/2));
    } // 在随机位置产生随机半径的金块,并在周围产生石头包围
}

// 在随机位置产生钻石
void Level::generateDiamonds(int numDiamonds){
    for (int i = 0;i < numDiamonds;i++){
        int x,y,radius;
        bool flag = false;
        while(!flag)
        {
            flag=true;
            x = QRandomGenerator::global()->bounded(0, 600);
            y = QRandomGenerator::global()->bounded(250, 350); // 钻石在比较上面
            radius = QRandomGenerator::global()->bounded(25, 35);
            for(GameObject* object:gameObjects)
            {
                if(object->type == GameObject::Type::Stone || object->type == GameObject::Type::Gold)
                    continue;
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < 2*(radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        gameObjects.push_back(new Diamond(QPoint(x, y), radius));
    }
}


void Level::generateTimePlus(int numTimePlus){
    for (int i = 0;i < numTimePlus;i++){
        int x,y,radius;
        bool flag = false;
        while(!flag)
        {
            flag=true;
            x = QRandomGenerator::global()->bounded(0, 600);
            y = QRandomGenerator::global()->bounded(350, 550); // 时间道具在比较下面
            radius = QRandomGenerator::global()->bounded(25, 35);
            for(GameObject* object:gameObjects)
            {
                if(object->type == GameObject::Type::Stone || object->type == GameObject::Type::Gold)
                    continue;
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < 2*(radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        gameObjects.push_back(new TimePlus(QPoint(x, y), radius));
    }
}


void Level::generateBags(int numBags){
    for (int i = 0;i < numBags;i++){
        int x,y,radius;
        bool flag = false;
        while(!flag)
        {
            flag=true;
            x = QRandomGenerator::global()->bounded(0, 600);
            y = QRandomGenerator::global()->bounded(0, 300); // 时间道具在比较下面
            radius = QRandomGenerator::global()->bounded(25, 35);
            for(GameObject* object:gameObjects)
            {
                if(object->type == GameObject::Type::Stone || object->type == GameObject::Type::Gold)
                    continue;
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < 2*(radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        gameObjects.push_back(new Bag(QPoint(x, y), radius));
    }
}


void Level::paintGameObjects()
{
    QPainter painter(this);
    for(const GameObject* object:gameObjects)
    {
        object->draw(painter);
    }
}

void Level::drawLine()
{
    QPainter painter(this);
    if(hook)
        hook->drawLine(painter);
}//这个好像必须要单独出来写成一个函数我也不知道为什么

void Level::drawBombImage()
{
    QImage bombImage("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/bomb.png");
    bombImage = bombImage.scaled(ui->hookLabel->width()/2,ui->hookLabel->height()/2);//设置图片大小
    QPainter painter(this);
    painter.drawImage(
        Bomb::bombImagePosition -
            QPoint(ui->hookLabel->width() / 4, ui->hookLabel->height() / 4),
        bombImage); // 在特定位置画出图片
}

void Level::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    ui->scoreLabel->setText(QString("分数:%1").arg(score));
    ui->bombNumLabel->setText(QString("剩余炸药数量:%1").arg(Bomb::bombNum));
    paintGameObjects();
    drawLine();
    if(Bomb::bombImageTime > 0)
        drawBombImage();
}

void Level::updateTimer()
{
    restTime--;
    if(Bomb::bombImageTime > 0)
        Bomb::bombImageTime--;
    ui->timeLabel->setText(QString("剩余时间:%1s").arg(restTime));
    update();
    if(restTime == 0)
    {
        this->close();
        if(score < goalScore)
        {
            EndGameDialog *endGameDialog = new EndGameDialog(score,levelNum,false);
            endGameDialog->show();
        }
        else
        {
            EndGameDialog *endGameDialog = new EndGameDialog(score,levelNum,true);
            endGameDialog->show();
        }
    }
}

Level::~Level()
{
    delete hook;
    delete ui;
}
