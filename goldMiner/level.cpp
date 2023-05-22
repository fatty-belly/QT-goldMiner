#include "level.h"
#include "endgamedialog.h"
#include "hook.h"
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
    minerPixmap("../goldMiner/Images/goldminer.png"),
    restTime(60)
{
    ui->setupUi(this);
    ui->minerLabel->setPixmap(minerPixmap);
    hook = new Hook(ui, this);
    QTimer *gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &Level::updateTimer);
    gameTimer->start(1000);
    generateRandomObjects(10,10);
    repaint();
}

void Level::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Down)
    {
        hook->extend();
    }
}

void Level::generateRandomObjects(int numStones,int numGolds)
{
    for(int i=1; i<=numStones; i++)
    {
        int x = QRandomGenerator::global()->bounded(0, 600);
        int y = QRandomGenerator::global()->bounded(150, 350);
        gameObjects.push_back(new Stone(QPoint(x,y),QRandomGenerator::global()->bounded(10, 50)));
    }
    for(int i=1; i<=numGolds; i++)
    {
        int x = QRandomGenerator::global()->bounded(0, 600);
        int y = QRandomGenerator::global()->bounded(150, 350);
        gameObjects.push_back(new Gold(QPoint(x,y),QRandomGenerator::global()->bounded(10, 50)));
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

void Level::paintEvent(QPaintEvent* event)
{
    ui->scoreLabel->setText(QString("分数:%1").arg(score));
    paintGameObjects();
}

void Level::updateTimer()
{
    restTime--;
    ui->timeLabel->setText(QString("剩余时间:%1s").arg(restTime));
    repaint();
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
