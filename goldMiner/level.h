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
    explicit Level(QWidget *parent = nullptr);
    ~Level();
    std::vector<GameObject*> gameObjects;//关卡内所有现存物体
    int score;//总得分

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void generateRandomObjects(int numStones,int numGolds);//初始化随机产生物体
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
};

#endif // LEVEL_H
