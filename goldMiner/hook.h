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
    void extend();
    void updateHook();
    ~Hook();

private:
    Ui::Level *ui;
    Level* level;
    QPixmap hookPixmap;
    int angel = 0;
    bool clockwise=false;
    bool hookExtended=false;
    bool extend_direction = true;
    int startX,startY;
    QPointF position;
    double speed = 5;
    GameObject* caughtObject = NULL;
};

#endif // HOOK_H
