#ifndef OBJECTS_H
#define OBJECTS_H

#include "CTRLVARS.h"

#include "QGraphicsScene"
#include <QGraphicsPixmapItem>
#include <SpriteList.h>
#include <QFont>
#include <QtDebug>

// The base class of onscreen objects
class render_object
{
    //Position Data
    int spotX=0,spotY=1;
    int center_offset_x = 0,center_offset_y = 0;

    //Image Data
    QList<spriteframe> *  sprite_list;
    int sprite_index = 0;
    qreal scale = 1;
    int dur_index= 0;
    spriteframe cursprite;

public:
    int x=0,y=0;
    QGraphicsItem * sprite;
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

    void setCenterOffset(int a, int b);

    void setSpriteSingle(QPixmap single);// Do not use on animation

    //Pulls in a list of sprites and sets the indicated one from index
    void initSprite_List(QList<spriteframe>* sfl,int si);

    void setSprite(spriteframe newsprite);// Sets the sprite of player

    int getPosX();// Return X position
    int getPosY();// Return Y position
    int getSpotX();//Return X spot
    int getSpotY();// Return Y spot
    int getZVal();// Returns Depth
    sprite_dump getGenes();//Returns Pointers for children

    qreal getScale();// Return Scale
    int getCenterOffsetX();// Return sprite offset X
    int getCenterOffsetY();// Return sprite offset Y
    QGraphicsItem*  getSprite() ;// Return image
    spriteframe getSpriteat(int si);// Returns sprite frame at index
    spriteframe getSpriteFrame();// Returns current sprite frame

    void push_to_scene(QGraphicsScene*);//Adds sprites to the scene
    void update_sprite();

    virtual void logic();
};

// A sub-class to be used in render objects
class render_item {
    int x; // x variable, or offset if has parent.
    int y; // y variable, of offset if has parent.
    QGraphicsPixmapItem * sprite; // Should be spriteframe, but is the sprite.
    render_object * parent = NULL;// Parent to take data from.

    spriteframe * SPRITE;// Testing for spriteframe replacement.

public:
    render_item();// Base constructor
    render_item(sprite_dump);// Constructor when parent exists.
    void setParent(render_object *);
    void setXY(int,int);// Changes sprite position. Parent = relative,!= absolute
    void setScale(qreal);
    void setSprite(QString);// Changes the sprite.
    void logic(bool);// Runs logic if needed.
    QGraphicsPixmapItem * getSprite();// Returns the current sprite.
};

// An extension of render object that responds to controls
class controllable_object:public render_object
{
public:
    short health = 1000, curhealth = 700;

    controllable_object(QList<spriteframe> * sprite_list,
                        int sprite_index,int x_location, int y_locatioin,
                        qreal scale,int center_offset_x,int center_offset_y);

    void moveself(bool,bool,bool,bool);
    void logic();//TODO unique player logic
};

// An extension of render object that is algorithmically driven
class enemy_object:public render_object
{
public:
    short health = 1000;
    short curhealth = 700;
    enemy_object(QList<spriteframe> * spr_list,int spr_index,int x, int y,
                 qreal scale,int center_offset_x,int center_offset_y);
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

// An extension of render object that displays text
class text_object: public render_object
{
public:
    text_object(int X, int Y, qreal depth, QString Text, QFont Font = QFont("sans",40));
    void setText(QString Text);
    void setFont(QFont Font);
    QString getText();
    QFont getFont();
    void logic();
};

// An extension of render object that has multiple sprites attatched
class group_object: public render_object
{
    int items;
    QList<render_item*> R_items;
    bool update_children;
public:
    group_object();// Base constructor
    void setXY(int,int);
    void add_Item(render_item*);// Adds a render item to the group
    void push_to_scene(QGraphicsScene *);// Adds the entire item list to the scene
    void logic();// Runs logic on all the render items
};

#endif // OBJECTS_H
