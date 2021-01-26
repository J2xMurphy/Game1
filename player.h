#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <iostream>

class mainActor:public QObject{
Q_OBJECT
    QGraphicsRectItem * pRect = new QGraphicsRectItem;
public:
    QGraphicsRectItem * getRect();
public slots:
    void moveSelf(int);
    void move(bool,bool,bool,bool);
    void setCenteredRect(int,int,int,int);
};

#endif // PLAYER_H
