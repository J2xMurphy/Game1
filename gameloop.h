#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "keyHandler.h"
#include "player.h"
#include "objects.h"

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>
#include <iostream>
#include <SpriteList.h>
#include <list>
#include <QApplication>

//A per frame logic handler
// The backbone of game logic and realtime functionality
class gameloop: public QObject{
    Q_OBJECT
    keyWatcher * input;
    QGraphicsScene * scene;
    QApplication * app;
public:
    void initialize(QGraphicsScene * scene, QApplication * a);//Call on start
    bool do_loop();//Call to loop game logic
public slots:
    void restart(){do_loop();};
};

#endif // GAMELOOP_H
