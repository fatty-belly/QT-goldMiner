#ifndef HOOK_H
#define HOOK_H

#include "ui_level.h"
#include <level.h>
#include <QObject>

class Hook:public QObject
{
    Q_OBJECT

public:
    Hook(Ui::Level *u, Level *l);
    void extend();//伸出钩子
    void bomb();//扔炸药
    void updateHook();//更新钩子状态，包含旋转与伸出/收回
    void drawLine(QPainter& painter) const;//画连接钩子那根线
    ~Hook();
    QPointF position;//钩子现在的位置
    GameObject* caughtObject = NULL;//钩子抓取到的物体
    double multiplier = 1.2;


private:
    Ui::Level *ui;
    Level* level;
    QPixmap hookPixmap;
    int angel = 0;//钩子旋转角
    bool clockwise=false;//顺时针/逆时针
    bool hookExtended=false;//是否处于伸出状态
    bool extend_direction = true;//是否是往前伸出
    int startX,startY;//初始钩子位置
    double speed = 5; //钩子速度
};

#endif // HOOK_H
