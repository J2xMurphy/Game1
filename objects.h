#ifndef OBJECTS_H
#define OBJECTS_H

#include "CTRLVARS.h"

#include <QGraphicsPixmapItem>
#include <SpriteList.h>


class render_object
{
    //Position Data
    int x=0,y=0;
    int spotX=0,spotY=1;

    //Image Data
    QList<spriteframe> *  sprite_list;
    int sprite_index = 0;
    qreal scale = 1;
    int dur_index= 0;
    int center_offset = 0;
    spriteframe cursprite;

public:
    QGraphicsPixmapItem * sprite;
    // Constructors --------------
    // ---------------------------
    render_object();
    render_object(int X_Position, int Y_Position,
                  QList<spriteframe> * Sprite_List, int Sprite_Index);
    render_object(int X_Position, int Y_Position,
                  QList<spriteframe> * Sprite_List, int Sprite_Index, int Depth);
    render_object(int X_Position, int Y_Position,
                  qreal Scale,QList<spriteframe> * Sprite_List, int Sprite_Index);
    render_object(int X_Position, int Y_Position,
                  qreal Scale,spriteframe Spriteframe, qreal z=0);

    // Functions -----------------
    // ---------------------------
    void init_Sprite(QList<spriteframe> * spl, int si);

    void setX(int X_Position);// Set X position
    void setY(int Y_Position);// Set Y position
    void setXY(int X_Position,int Y_Position); // Set X and Y position
    void setZVal(int Depth);// Sets Depth
    void setScale(qreal Scale);// Sets Scale

    void setSpotX(int a);// Sets the spot x on the battle grid
    void setSpotY(int b);// Sets the spot Y on the battle grid
    void setSpotXY(int a, int b);//Sets both spotX and spotY

    void setCenterOffset(int a);

    void setSpriteSingle(QPixmap single);// Do not use on animation

    //Pulls in a list of sprites and sets the indicated one from index
    void initSprite_List(QList<spriteframe>* sfl,int si);

    void setSprite(spriteframe newsprite);// Sets the sprite of player

    int getPosX();// Return X position
    int getPosY();// Return Y position
    int getSpotX();//Return X spot
    int getSpotY();// Return Y spot
    int getZVal();// Returns Depth

    qreal getScale();// Return Scale
    int getCenterOffset();// Return sprite offset
    QGraphicsPixmapItem*  getSprite() ;// Return image
    spriteframe getSpriteat(int si);// Returns sprite frame at index
    spriteframe getSpriteFrame();// Returns current sprite frame

    void update_sprite();

    virtual void logic();
};

// An extension of render object that responds to controls
class controllable_object:public render_object
{
public:
    short health = 1000, curhealth = 700;

    controllable_object(QList<spriteframe> * sprite_list,
                        int sprite_index,int x_location, int y_locatioin,
                        qreal scale,int center_offset);

    void moveself(bool,bool,bool,bool);
    void logic();//TODO unique player logic
};

// An extension of render object that is algorithmically driven
class enemy_object:public render_object
{
public:
    short health = 1000;
    short curhealth = 700;
    int x_spot = 3; // the x tile of the enemy
    int y_spot = 1; // the y tile of the enemy
    enemy_object(QList<spriteframe> * spr_list,int spr_index,
                 int x, int y,qreal scale,int cof);
    void logic();
};

// An extension of render object that deals with bar indicators
class bar_object:public render_object
{
public:
    short curhealth = 500;
    short maxhealth = 1000;
    bar_object();
    bar_object(int x, int y, spriteframe spl);
    bar_object(int x, int y, qreal z, spriteframe spl);
    void logic();
};

// An extension of render object that does not change
class static_object:public render_object
{
public:
    static_object();
    static_object(int x, int y, spriteframe spl);
    static_object(int x, int y, qreal scale ,qreal depth,spriteframe spl);
};

class text_object
{
    int x,y;
    QGraphicsSimpleTextItem * text;
public:
    text_object(int X, int Y, QString Text);
    void setX(int X);
    void setY(int Y);
    void setText(QString Text);
    int getX();
    int getY();
    QString getText();
};

#endif // OBJECTS_H
