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

Level::Level(QWidget *parent) :
    QWidget(parent),
    score(0),
    ui(new Ui::Level),
    minerPixmap("/Users/zhaohaonan/Desktop/北大资料/Coding/C++/程序设计实习/QT-goldMiner/goldMiner/Images/goldminer.png"),
    restTime(90)
{
    ui->setupUi(this);
    ui->minerLabel->setPixmap(minerPixmap);
    hook = new Hook(ui, this);
    QTimer *gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level::updateTimer);
    gameTimer->start(1000);
    generateRandomObjects(8,12);
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

void Level::generateRandomObjects(int numStones,int numGolds)
{
    for(int i=1; i<=numStones; i++)
    {
        int x = QRandomGenerator::global()->bounded(0, 600);
        int y = QRandomGenerator::global()->bounded(150, 300);//石头在比较上面
        gameObjects.push_back(new Stone(QPoint(x,y),QRandomGenerator::global()->bounded(10, 50)));
    }//在随机位置产生随机半径的石头
    for(int i=1; i<=numGolds; i++)
    {
        int x = QRandomGenerator::global()->bounded(0, 600);
        int y = QRandomGenerator::global()->bounded(200, 350);//金块在比较下面
        gameObjects.push_back(new Gold(QPoint(x,y),QRandomGenerator::global()->bounded(10, 50)));
    }//在随机位置产生随机半径的金块
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
        EndGameDialog *endGameDialog = new EndGameDialog(score);
        endGameDialog->show();
    }
}

Level::~Level()
{
    delete hook;
    delete ui;
}
