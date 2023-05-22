#include "hook.h"
#include "qtimer.h"
#include "QPoint"
#include <QPainter>

Hook::Hook(Ui::Level *u, Level *l):
    ui(u),
    level(l),
    hookPixmap("../goldMiner/Images/hook.png"),
    angel(0),
    clockwise(false),
    hookExtended(false),
    extend_direction(true)
{
    ui->hookLabel->setPixmap(hookPixmap);
    position = QPoint(300,30);  // 获取当前位置
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Hook::updateHook);
    timer->start(50);
}

void Hook::updateHook()
{
    if(hookExtended)
    {
        double radians = qDegreesToRadians(angel);  // 将角度转换为弧度
        if(extend_direction)
        {
            for(GameObject* object:level->gameObjects)
            {
                //qDebug()<<object->position;
                if(sqrt(pow(position.x() + 50 - object->position.x(),2)
                         + pow(position.y() + 50 - object->position.y(),2)) < object->radius + 5)
                {
                    caughtObject = object;
                    extend_direction = false;
                    speed = caughtObject->hookSpeed;
                    break;
                }
            }
        }
        if (extend_direction && (position.x() < -20 || position.x() > 640 || position.y() > 380))
            extend_direction = false;
        if(!extend_direction && abs(position.x() - startX ) < 10 && abs(position.y() - startY) < 10 )
        {
            extend_direction = true;
            hookExtended = false;
            ui->hookLabel->move(300,30);
            position = QPointF(300,30);
            speed = 5;
            if(caughtObject)
            {
                level->score += caughtObject->score;
                level->gameObjects.erase(find(level->gameObjects.begin(),level->gameObjects.end(),caughtObject));
                caughtObject = NULL;
            }
            level->repaint();
            return;
        }
        if(extend_direction)
            position += QPointF(-speed * cos(radians), speed * sin(radians));
        else
        {
            position -= QPointF(-speed * cos(radians), speed * sin(radians));
            if(caughtObject)
            {
                caughtObject->position -= QPointF(-speed * cos(radians), speed * sin(radians));
                level->repaint();
            }
        }// 在当前位置的基础上向特定方向移动
        ui->hookLabel->move(position.x(),position.y());  // 设置新的位置
    }
    else
    {
        if(clockwise)
            --angel;
        else
            ++angel;
        if(angel >= 180 || angel <= 0)
            clockwise = !clockwise;
        QTransform transform;
        transform.rotate(-angel); // 旋转图片
        ui->hookLabel->setPixmap(hookPixmap.transformed(transform, Qt::SmoothTransformation));
    }
}

void Hook::extend()
{
    if(!hookExtended)
    {
        startX = ui->hookLabel->x();
        startY = ui->hookLabel->y();
        hookExtended = true;
    }
}

Hook::~Hook()
{
    delete ui;
}

