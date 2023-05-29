#include "hook.h"
#include "qtimer.h"
#include "QPoint"
#include <QPainter>
#include "bomb.h"

Hook::Hook(Ui::Level *u, Level *l):
    ui(u),
    level(l),
    hookPixmap("../goldMiner/Images/hook.png"),
    angel(0),
    clockwise(false),
    hookExtended(false),
    extend_direction(true),
    startX(ui->hookLabel->x()),
    startY(ui->hookLabel->y())
{
    ui->hookLabel->setPixmap(hookPixmap);
    position = ui->hookLabel->pos();  // 获取当前位置
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Hook::updateHook);
    timer->start(50);//50ms更新一次钩子状态
}

void Hook::updateHook()
{
    if(hookExtended)
    {
        double radians = qDegreesToRadians(angel);  // 将角度转换为弧度

        if(extend_direction)
        {
            for(GameObject* object:level->gameObjects)//逐个遍历所有物体
            {
                if(sqrt(pow(position.x() + ui->hookLabel->width() / 2 - object->position.x() , 2)
                         + pow(position.y() + ui->hookLabel->height()/2 - object->position.y() , 2))
                    < object -> radius + 5)//判断是否碰到物体
                {
                    caughtObject = object;
                    extend_direction = false;//往回收
                    speed = caughtObject->hookSpeed;//抓取物体后速度变化了
                    break;
                }
            }
        }

        if (extend_direction && (position.x() < -20 || position.x() > 640 || position.y() > 380))
            extend_direction = false;//碰到边缘返回

        if(!extend_direction &&
            abs(position.x() - startX) < 10 && abs(position.y() - startY) < 10)//已经回到原位
        {
            extend_direction = true;
            hookExtended = false;
            ui->hookLabel->move(startX, startY);
            position = QPointF(startX, startY);//回到“正确的”原位
            speed = 5;//重置速度
            if(caughtObject)
            {
                level->restTime += caughtObject->timeplus;
                Bomb::bombNum += caughtObject->bombplus;
                level->score += caughtObject->score;
                level->gameObjects.erase(find(level->gameObjects.begin(),level->gameObjects.end(),caughtObject));
                if (caughtObject->type == GameObject::Type::Strengup){
                    //增加文字说明strength up
                    multiplier *= 2;
                    level->StrengupTimeDeq.push_back(10);
                }

                if (caughtObject->type == GameObject::Type::Strengdown){
                    //增加文字说明strength down
                    multiplier /= 2;
                    level->StrengdownTimeDeq.push_back(10);
                }
                caughtObject = NULL;
            }//如果抓到了物体，就得分并删除物体
            level->update();//更新画面
            return;
        }

        if(extend_direction)
            position += QPointF(-speed * multiplier * cos(radians), speed * multiplier * sin(radians));
        else
        {
            position -= QPointF(-speed * multiplier * cos(radians), speed * multiplier * sin(radians));
            if(caughtObject)
            {
                caughtObject->position -= QPointF(-speed * multiplier * cos(radians), speed * multiplier * sin(radians));
                level->update();
            }//物体要随着抓钩移动
        }// 在当前位置的基础上向特定方向移动
        ui->hookLabel->move(position.x(),position.y());  // 设置新的位置
    }
    else
    {
        if(clockwise)
            angel -= 2;
        else
            angel += 2;
        if(angel >= 180 || angel <= 0)
            clockwise = !clockwise;
        QTransform transform;
        transform.rotate(-angel); // 旋转图片
        ui->hookLabel->setPixmap(hookPixmap.transformed(transform, Qt::SmoothTransformation));
    }//旋转抓钩
}

void Hook::extend()
{
    if(!hookExtended)
    {
        hookExtended = true;
    }
}//处理伸出这一事件

void Hook::bomb()
{
    if(caughtObject && Bomb::bombNum > 0)//如果抓到了物体并且还有炸弹就扔炸弹
    {
        Bomb::bombNum--;
        Bomb::bombImageTime = 1;
        Bomb::bombImagePosition = caughtObject->position;//炸弹位置是抓取的物体的位置
        level->update();
        level->gameObjects.erase(find(level->gameObjects.begin(),level->gameObjects.end(),caughtObject));
        caughtObject = NULL;
        speed = 5;//以上为把物体删除的操作
    }
}

void Hook::drawLine(QPainter& painter) const
{
    painter.setRenderHint(QPainter::Antialiasing); //抗锯齿
    painter.setPen(QPen(QColor(Qt::black),2));//颜色与线条宽度
    painter.drawLine(QPoint(startX + ui->hookLabel->width() / 2, startY + ui->hookLabel->height() / 2),
                     position + QPoint(50, 50)); // 两个点连线
}

Hook::~Hook()
{
    delete ui;
}
