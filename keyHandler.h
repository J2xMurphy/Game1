#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <iostream>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QObject>
#include"CTRLVARS.h"

extern int myexternvar;

class cbtn{
public:
    int id;
    bool tapped,held;
    cbtn(int a = 0){
        id = a;
        held = false;
        tapped = false;
    }
};

class keyWatcher:public QGraphicsTextItem{
    Q_OBJECT
public:
    cbtn clist[4];
    int o = 0;
    void btndef(int,int,int,int);
    void keyPressEvent(QKeyEvent * keypress);
    void keyReleaseEvent(QKeyEvent *event);
    void logic();
signals:
    void keyPressed(int o);
    void UDLDHeld(bool,bool,bool,bool);
public slots:
    void showKey();
    void keyApply();
};

#endif // KEYHANDLER_H
