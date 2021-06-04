#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "keyHandler.h"
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

//#############################################################################
//A per frame logic handler
// The backbone of game logic and realtime functionality
class gameloop:public QObject{
    Q_OBJECT
    keyWatcher * input;
    QGraphicsScene * scene;
    QApplication * app;
public:
    void initialize(QGraphicsScene * Graphics_Scene, QApplication * App);//Call on start
    void init_input();//Initializes the keyWatcher that handles input
    void init_objects();//Adds Non-player/enemy objects to the scene
    void init_player();//Adds the player to the scene
    void init_enemy();//Adds the enemy to the scene
    void init_logic();//Starts the framerate timer that handles object logic
    bool do_loop();//Call to loop game logic
public slots:
    void restart(){do_loop();};
};


#endif // GAMELOOP_H
