#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <iostream>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QObject>
#include"CTRLVARS.h"

extern int myexternvar;

// A button data store to dynamically tell what button and if
//   the button has just been pressed, or is being held.
//   button_id refers to the getkey value
class control_button{
public:
    int button_id;
    bool tapped,held;
    control_button(int button_id=0);
};

// key Watcher handles all of the buttons and timings for input
class keyWatcher:public QGraphicsTextItem{
    Q_OBJECT
public:
    control_button clist[4];
    int o = 0;
    void buttondef(int,int,int,int);
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
