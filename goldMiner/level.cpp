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
#include <deque>
#include <QSoundEffect>


int Level::totalLevelNum = 6;

Level::Level(QWidget *parent, int levelNum_) :
    QWidget(parent),
    score(0),
    restTime(90),
    ui(new Ui::Level),
    levelNum(levelNum_)
{
    ui->setupUi(this);
    ui->minerLabel->setPixmap(QPixmap("../goldMiner/Images/goldminer1.png"));
    gameObjects.clear();
    StrengthDownTimeDeq.clear();
    StrengthUpTimeDeq.clear();
    hook = new Hook(ui, this);
    goal_play_once = true;
    connect(gameTimer, &QTimer::timeout, this, &Level::updateTimer);

    // 添加BGM
    player = new QSoundEffect();
    player->setSource(QUrl::fromLocalFile("../goldMiner/Music/level_bgm.wav"));
    player->setLoopCount(QSoundEffect::Infinite);
    player->stop();
    timePlayer = new QSoundEffect();
    goalPlayer = new QSoundEffect();
    //player->setVolume(0.4);

    if (levelNum == 1)
    {
        gameTimer->start(1000);
    }
    switch(levelNum)
    {
    case 1:
        generateProps(5);
        generateDiamonds(2);
        generateRandomObjects(8,10);//第一关-正常关
        goalScore = 8000;
        Bomb::bombNum = 5;
        break;
    case 2:
        generateProps(5);
        generateDiamonds(1);
        generateTimePlus(1);
        goalScore = 10000;
        generateRandomObjects(10,10);//第二关-正常关
        break;
    case 3:
        generateTimePlus(2);
        generateDiamonds(20);//第三关-钻石关
        goalScore = 38000;
        restTime = 120;
        break;
    case 4:
        generateTimePlus(2);
        generateRandomObjects(20,5,true);//第四关-碎石关
        generateTNT(3);
        goalScore = 6000;
        break;
    case 5:
        generateTimePlus(2);
        generateSpecialObjects(5);//第五关-雪花关
        generateTNT(2);
        goalScore = 7000;
        break;
    case 6:
        generateTimePlus(20, true);//第六关-时钟关
        goalScore = 18;
        restTime = 20;
        break;
    }
    ui->goalScoreLabel->setText(QString("目标分数:%1").arg(goalScore));
    update();
}



void Level::keyPressEvent(QKeyEvent *event)
{
    if(hook)
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
                y = QRandomGenerator::global()->bounded(120, 350); // 石头在比较上面
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
                y = QRandomGenerator::global()->bounded(200, 400); // 金块在比较下面
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
            y = QRandomGenerator::global()->bounded(150, 350);
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
            y = QRandomGenerator::global()->bounded(120, 300); // 钻石在比较上面
            radius = QRandomGenerator::global()->bounded(10, 12);
            for(GameObject* object:gameObjects)
            {
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < (radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        gameObjects.push_back(new Diamond(QPoint(x, y), radius));
    }
}


void Level::generateTimePlus(int numTimePlus, bool shortTime){
    for (int i = 0;i < numTimePlus;i++){
        int x,y,radius;
        bool flag = false;
        while(!flag)
        {
            flag=true;
            x = QRandomGenerator::global()->bounded(0, 600);
            y = QRandomGenerator::global()->bounded(200, 400); // 时间道具在比较下面
            radius = QRandomGenerator::global()->bounded(15, 20);
            for(GameObject* object:gameObjects)
            {
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < (radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        gameObjects.push_back(new TimePlus(QPoint(x, y), radius, shortTime));
    }
}


void Level::generateProps(int numProps){
    for (int i = 0;i < numProps;i++){
        int x,y,radius;
        bool flag = false;
        while(!flag)
        {
            flag=true;
            x = QRandomGenerator::global()->bounded(0, 600);
            y = QRandomGenerator::global()->bounded(120, 400);
            radius = QRandomGenerator::global()->bounded(25, 35);
            for(GameObject* object:gameObjects)
            {
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < (radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        switch(QRandomGenerator::global()->bounded(0, 4))
        {
        case 0:
            gameObjects.push_back(new Bag(QPoint(x, y), radius));
            break;
        case 1:
            gameObjects.push_back(new BombPlus(QPoint(x, y), radius));
            break;
        case 2:
            gameObjects.push_back(new StrengthUp(QPoint(x, y), radius));
            break;
        case 3:
            gameObjects.push_back(new StrengthDown(QPoint(x, y), radius));
            break;
        }
    }
}

void Level::generateTNT(int numTNTs){
    for (int i = 0;i < numTNTs;i++){
        int x,y,radius;
        bool flag = false;
        while(!flag)
        {
            flag=true;
            x = QRandomGenerator::global()->bounded(0, 600);
            y = QRandomGenerator::global()->bounded(150,350);
            radius = QRandomGenerator::global()->bounded(15, 20);
            for(GameObject* object:gameObjects)
            {
                if(sqrt(pow(x-object->position.x(), 2) + pow(y-object->position.y(), 2)) < (radius + object->radius))
                {
                    flag = false;
                    break;
                }
            }
        }//碰撞检测
        gameObjects.push_back(new TNT(QPoint(x, y), radius));
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
    QImage bombImage("../goldMiner/Images/bomb.png");
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
    if (score >= goalScore && goal_play_once){
        goalPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/起飞.wav"));
        goalPlayer->setLoopCount(1);
        goalPlayer->play();
        goal_play_once = false;
    }
    restTime--;
    std::deque<int>::iterator i;
    if (!StrengthUpTimeDeq.empty())
    {
        for(i=StrengthUpTimeDeq.begin();i != StrengthUpTimeDeq.end();i++)
        {
            (*i)--;
            if ((*i) == 0){
                hook->multiplier /= 1.5;
            }
        }
    }
    if (!StrengthDownTimeDeq.empty())
    {
        for(i=StrengthDownTimeDeq.begin();i != StrengthDownTimeDeq.end();i++)
        {
            (*i)--;
            if ((*i) == 0)
            {
                hook->multiplier *= 1.5;
            }
        }
    }
    if(Bomb::bombImageTime > 0)
        Bomb::bombImageTime--;
    ui->timeLabel->setText(QString("剩余时间:%1s").arg(restTime));
    update();
    if(restTime == 10)
    {
        timePlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/time.wav"));
        timePlayer->setLoopCount(2);
        timePlayer->play();
    }
    if(restTime > 10 && timePlayer->isPlaying())
        timePlayer->stop();
    if(restTime == 0 || (gameObjects.size() == 0 && restTime > 0))
    {
        restTime = -1;
        player->stop();
        goalPlayer->stop();
        hook->goldPlayer->stop();
        hook->hookfailPlayer->stop();
        hook->hookstartPlayer->stop();
        hook->bagPlayer->stop();
        hook->bombPlayer->stop();
        hook->diamondPlayer->stop();
        hook->pickstonePlayer->stop();
        hook->pickbombPlayer->stop();
        hook->stonePlayer->stop();
        hook->strengthdownPlayer->stop();
        hook->strengthupPlayer->stop();
        hook->timeplusPlayer->stop();
        if(score < goalScore)
        {
            EndGameDialog *endGameDialog = new EndGameDialog(0, levelNum, false);
            endGameDialog->show();
        }
        else
        {
            EndGameDialog *endGameDialog = new EndGameDialog(score - goalScore, levelNum,true);
            endGameDialog->show();
        }
        hook->hookTimer->stop();
        hook = NULL;
        this->close();
        gameTimer->stop();
    }
}

Level::~Level()
{
    delete hook;
    delete ui;
}
