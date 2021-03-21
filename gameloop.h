#ifndef GAMELOOP_H
#define GAMELOOP_H

#include "keyHandler.h"
#include "player.h"

#include <QObject>
#include <iostream>
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

//A renderobject that holds basic object data and sprite image
class render_object{
    //Position Data
    int x=0,y=0;
    int spotX=0,spotY=1;

    //Image Data
    QList<spriteframe> *  sprite_list;
    int sprite_index = 0;
    qreal scale = 1;
    int dur_index= 0;
    int center_offset = 0;
    QGraphicsPixmapItem * sprite = new QGraphicsPixmapItem;
    spriteframe cursprite;

public:
    // Constructors --------------
    // ---------------------------
    render_object(){}
    render_object(int x, int y, QList<spriteframe> * spl, int si){
        setXY(x,y);
        sprite_list = spl;
        sprite_index = si;
        setSprite(sprite_list->at(sprite_index));
    }
    render_object(int x, int y, QList<spriteframe> * spl, int si, int z){
        setXY(x,y);
        sprite_list = spl;
        sprite_index = si;
        setSprite(sprite_list->at(sprite_index));
        setZVal(z);
    }
    render_object(int x, int y, qreal z,QList<spriteframe> * spl, int si){
        setXY(x,y);
        sprite_list = spl;
        sprite_index = si;
        setSprite(sprite_list->at(sprite_index));
        setScale(z);
    }

    // Functions -----------------
    // ---------------------------
    void init_Sprite(QList<spriteframe> * spl, int si){
        sprite_list = spl;
        sprite_index = si;
        if (sprite_list->size()==0){
            std::cout << "Sprite List empty!!" << std::endl;
            return;
        }
        std::cout << sprite_list[0][sprite_index].getSprite().toStdString() << ": in list."<< std::endl;

        std::cout << "x1" << std::endl;
        cursprite = sprite_list[0].at(sprite_index);
        std::cout << "x2" << std::endl;
        setSprite(cursprite);
        std::cout << "x3" << std::endl;
    }

    void setX(int a){                   // Set X position
        x = a;
        sprite->setOffset(x,y);
    }

    void setY(int b){                   // Set Y position
        y = b;
        sprite->setOffset(x,y);
    };

    void setSpotX(int a);// Sets the spot x on the battle grid

    void setSpotY(int b);// Sets the spot Y on the battle grid

    void setSpotXY(int a, int b);

    void setXY(int a,int b){            // Set X and Y position
        x=a;
        y=b;
        sprite->setOffset(x,y);
    };

    void setZVal(int z){
        sprite->setZValue((qreal) z);
    }

    void setScale(qreal newscale){      // Scales the image
        scale = newscale;
        //sprite->pixmap().scaled(QSize(scale,scale));
        sprite->setScale(scale);
    };

    void setCenterOffset(int a){        // Sets the center
        center_offset=a;
    };

    void setSpriteSingle(QPixmap single){ // Do not use on animation
        sprite->setPixmap(single);
    };

    void setSprite(spriteframe newsprite){// Sets the sprite of player as newsprite
        std::cout << newsprite.getSprite().toStdString() << std::endl;
        dur_index = 0;
        std::cout << sprite << std::endl;
        std::cout << "z1" << std::endl;
        cursprite = newsprite;
        std::cout << "z2" << std::endl;
        sprite->setPixmap(QPixmap(cursprite.getSprite()));
        std::cout << "z3" << std::endl;
        std::cout << sprite << std::endl;
    };

    int getPosX(){// Return X position
        return x;
    };

    int getPosY(){// Return Y position
        return y;
    };

    int getSpotX(){
        return spotX;
    };

    int getSpotY(){
        return spotY;
    };

    int getZVal(){
        return sprite->zValue();
    }

    qreal getScale(){// Return Scale
        return scale;
    };

    int getCenterOffset(){// Return sprite offset
        return center_offset;
    };

    QGraphicsPixmapItem*  getSprite() {// Return image
        return sprite;
    };

    spriteframe getSpriteat(int si){
      return sprite_list->at(si);
    };

    spriteframe getSpriteFrame(){
        return cursprite;
    };

    virtual void logic(){
        if (cursprite.getDuration()!=0){
            dur_index++;
            if (dur_index >=cursprite.getDuration()){
              dur_index = 0;
              sprite_index=cursprite.get_Next_Index();
              cursprite = sprite_list[0].at(sprite_index);
              sprite->setPixmap(QPixmap(cursprite.getSprite()));
            }
        }
    };

};



// An extension of render object that responds to controls
class controllable_object:public render_object{
public:
    short health = 1000, curhealth = 700;
    void moveself(bool,bool,bool,bool);
};

// An extension of render object that is algorithmically driven
class enemy_object:public render_object{
public:
    short health = 1000, curhealth = 700;
    int x_spot = 3; // the x tile of the enemy
    int y_spot = 1; // the y tile of the enemy
};

// An extension of render object that deals with bar indicators
class bar_object:public render_object{
public:
    //using render_object::render_object;
    bar_object(){}
    bar_object(int x, int y, QList<spriteframe>* spl, int si){
        setXY(x,y);
        setSprite(spl->at(si));
    }
    bar_object(int x, int y, qreal z, QList<spriteframe>* spl, int si){
        setXY(x,y);
        setScale(z);
        setSprite(spl->at(si));
    }
    void logic() override;
};
#endif // GAMELOOP_H
