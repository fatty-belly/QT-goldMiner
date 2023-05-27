#ifndef LEVEL_H
#define LEVEL_H

#include <QWidget>
#include <QTimer>
#include <gameobject.h>
#include <vector>

namespace Ui {
class Level;
}

class Hook;

class Level : public QWidget
{
    Q_OBJECT

public:
    explicit Level(QWidget *parent = nullptr, int levelNum_ = 1);//levelNum代表第几关
    ~Level();
    std::vector<GameObject*> gameObjects;//关卡内所有现存物体
    int score;//总得分
    static int totalLevelNum;//总共关卡的数量


protected:
    void keyPressEvent(QKeyEvent *event) override;
    void generateRandomObjects(int numStones,int numGolds,int special = false);//初始化随机产生物体
    void generateSpecialObjects(int numGolds);//产生金块和石头组成雪花的物体
    void paintGameObjects();//打印物体
    void drawLine();//画出连接钩子的线
    void paintEvent(QPaintEvent* event) override;//打印关卡所有东西
    void updateTimer();//倒计时
    void drawBombImage();//画出炸药的特效

private:
    Ui::Level *ui;
    QPixmap minerPixmap;
    Hook* hook = NULL;
    int restTime;//剩余时间
    int levelNum;//第几关
    int goalScore;
};

#endif // LEVEL_H
