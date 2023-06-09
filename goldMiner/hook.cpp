#include "hook.h"
#include "qtimer.h"
#include "QPoint"
#include <QPainter>
#include "bomb.h"
#include <gameobject.h>

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
    connect(hookTimer, &QTimer::timeout, this, &Hook::updateHook);
    hookTimer->start(60);//60ms更新一次钩子状态
    stone_play_once = true;
    bag_play_once = true;
    bomb_play_once = true;

    goldPlayer = new QSoundEffect();
    goldPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/gold.wav"));
    goldPlayer->setLoopCount(1);

    bombPlayer = new QSoundEffect();
    bombPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/TNT.wav"));
    bombPlayer->setLoopCount(1);

    bagPlayer = new QSoundEffect();
    bagPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/bag.wav"));
    bagPlayer->setLoopCount(1);

    pickstonePlayer = new QSoundEffect();
    pickstonePlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/pickstone.wav"));
    pickstonePlayer->setLoopCount(1);

    pickbombPlayer = new QSoundEffect();
    pickbombPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/pickbomb.wav"));
    pickbombPlayer->setLoopCount(1);

    hookfailPlayer = new QSoundEffect();
    hookfailPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/走位.wav"));
    hookfailPlayer->setLoopCount(1);

    stonePlayer = new QSoundEffect();
    stonePlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/stone.wav"));
    stonePlayer->setLoopCount(1);

    diamondPlayer = new QSoundEffect();
    diamondPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/diamond.wav"));
    diamondPlayer->setLoopCount(1);

    strengthupPlayer = new QSoundEffect();
    strengthupPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/strengthup.wav"));
    strengthupPlayer->setLoopCount(1);

    strengthdownPlayer = new QSoundEffect();
    strengthdownPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/strengthdown.wav"));
    strengthdownPlayer->setLoopCount(1);

    timeplusPlayer = new QSoundEffect();
    timeplusPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/timeplus.wav"));
    timeplusPlayer->setLoopCount(1);

    hookstartPlayer = new QSoundEffect();
    hookstartPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/hook.wav"));
    hookstartPlayer->setLoopCount(1);

    bombPlayer = new QSoundEffect();
    bombPlayer->setSource(QUrl::fromLocalFile("../goldMiner/Music/TNT.wav"));
    bombPlayer->setLoopCount(1);
}

void Hook::updateHook()
{
    if(level->restTime <= 0)
        return;
    if(hookExtended)
    {
        // 钩到TNT
        if (!extend_direction && caughtObject && caughtObject->type == GameObject::Type::TNT){
            bombPlayer->play();
            for(auto it = level->gameObjects.begin(); it!=level->gameObjects.end() ;)//逐个遍历所有物体
            {
                if (pow((*it)->position.x() - caughtObject->position.x(),2) +
                        pow((*it)->position.y() - caughtObject->position.y(), 2) < 5000)
                {
                    if ((*it) != caughtObject)
                    {
                        it = level->gameObjects.erase(it);
                        continue;
                    }
                }
                ++it;
            }
            Bomb::bombImageTime = 2;
            Bomb::bombImagePosition = caughtObject->position;//炸弹位置是抓取的物体的位置
            level->gameObjects.erase(find(level->gameObjects.begin(),level->gameObjects.end(),caughtObject));
            caughtObject = NULL;
            level->update();
            speed = 5;//以上为把物体删除的操作
        }

        // 钩到bag
        if (!extend_direction && caughtObject && caughtObject->type == GameObject::Type::Bag && bag_play_once){
            bagPlayer->play();
            bag_play_once = false;
        }

        // 钩到stone
        if (!extend_direction && caughtObject && caughtObject->type == GameObject::Type::Stone && stone_play_once){
            pickstonePlayer->play();
            stone_play_once = false;
        }

        // 钩到bomb
        if (!extend_direction && caughtObject && caughtObject->type == GameObject::Type::BombPlus && bomb_play_once){
            pickbombPlayer->play();
            bomb_play_once = false;
        }
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
                    ui->minerLabel->setPixmap(QPixmap("../goldMiner/Images/goldminer2.png"));
                    speed = caughtObject->hookSpeed;//抓取物体后速度变化了
                    break;
                }
            }
        }//判断物体抓取

        if (extend_direction && (position.x() < -30 || position.x() > 650 || position.y() > 390)){
            extend_direction = false;//碰到边缘返回
            hookfailPlayer->play();

        }

        if(!extend_direction &&
            abs(position.x() - startX) < 10 && abs(position.y() - startY) < 10)//已经回到原位
        {
            ui->minerLabel->setPixmap(QPixmap("../goldMiner/Images/goldminer1.png"));
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

                // 金块
                if (caughtObject->type == GameObject::Type::Gold){

                    goldPlayer->play();
                }

                // 石头
                if (caughtObject->type == GameObject::Type::Stone){
                    pickstonePlayer->stop();
                    stonePlayer->play();
                }

                // 钻石
                if (caughtObject->type == GameObject::Type::Diamond){
                    diamondPlayer->play();
                }

                // 大力药水
                if (caughtObject->type == GameObject::Type::StrengthUp){
                    //增加文字说明strength up
                    multiplier *= 1.5;
                    level->StrengthUpTimeDeq.push_back(20);
                    strengthupPlayer->play();
                }

                // 减弱药水
                if (caughtObject->type == GameObject::Type::StrengthDown){
                    //增加文字说明strength down
                    multiplier /= 1.5;
                    level->StrengthDownTimeDeq.push_back(20);
                    strengthdownPlayer->play();
                }

                // 钩到timeplus
                if (caughtObject->type == GameObject::Type::TimePlus){
                    timeplusPlayer->play();
                }

                // 钩到bombplus
                if (caughtObject->type == GameObject::Type::BombPlus){
                    pickbombPlayer->stop();
                }

                // 钩到bag
                if (caughtObject->type == GameObject::Type::Bag){
                    bagPlayer->stop();
                }

                level->gameObjects.erase(find(level->gameObjects.begin(),level->gameObjects.end(),caughtObject));
                caughtObject = NULL;

                stone_play_once = true;
                bag_play_once = true;
                bomb_play_once = true;
            }//如果抓到了物体，就得分并删除物体
            level->update();//更新画面
            return;
        }
        double radians = qDegreesToRadians(angel);  // 将角度转换为弧度
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
        hookstartPlayer->play();
        ui->minerLabel->setPixmap(QPixmap("../goldMiner/Images/goldminer3.png"));
    }
}//处理伸出这一事件

void Hook::bomb()
{
    if(caughtObject && Bomb::bombNum > 0)//如果抓到了物体并且还有炸弹就扔炸弹
    {
        bombPlayer->play();
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
