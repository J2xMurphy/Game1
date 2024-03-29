#ifndef SPRITELIST_H
#define SPRITELIST_H

#include <QPixmap>
#include <iostream>
#include <QGraphicsPixmapItem>

struct sprite_map{
    int duration;
    QString img;
};

struct sprite_link{
    sprite_map sprite;
    sprite_map * next;
};

struct sprite_dump{
    int * x;
    int * y;
};

//Spriteframe is essentailly a linked list that has data of:
//  [1] when to swap with next image/link
//  [2] the image that is to be displayed currently
//  [3] the preferred next spriteframe to be set if animated externally
class spriteframe{
private:
    int duration = 0;
    QString sprite = ":/Data/Sprites/circle.png";
    int next_index = 0;
public:
//##Declarations###############################################################
    spriteframe();// Non-setter:Requires use of "init" later
    spriteframe(int duration ,QString img_path ,int next_index);//Uses init
    spriteframe(QString path);// Sets [2]

//##Setters####################################################################
    void init(int duration,QString img_path,int next_index);
    void setDuration(int duration);
    void setSprite(QString img_path);
    void setNextIndex(int next_index);

//##Getters####################################################################
    int get_Next_Index();
    QString getSprite();
    int getDuration();
};

spriteframe spr_create(QString);
spriteframe spr_create(int,QString,int);
void sprite_appender(QList<spriteframe>*,QList<spriteframe>);


//#############################################################################
//LIST OF ALL THE SPRITES IN THE GAME
//#############################################################################

//TIM SPRITE
#define IDLE1_IMG ":/Data/Sprites/Idle1.png"
#define IDLE2_IMG ":/Data/Sprites/Idle2.png"

#define FORWARD_IMG1 ":/Data/Sprites/Forward1_Test.png"
#define FORWARD_IMG2 ":/Data/Sprites/Forward2_Test.png"
#define FORWARD_IMG3 ":/Data/Sprites/Forward3_Test.png"

#define BACKWARDS_IMG1 ":/Data/Sprites/Backwards1_Test.png"
#define BACKWARDS_IMG2 ":/Data/Sprites/Backwards2_Test.png"
#define BACKWARDS_IMG3 ":/Data/Sprites/Backwards3_Test.png"

//UI SPRITE
#define BASEHEALTHBAR   ":/Data/Sprites/Base_hp.png"
#define FRONTHEALTHBAR  ":/Data/Sprites/front_hp.png"
#define FRONTSPECIALBAR ":/Data/Sprites/front_mp.png"
#define TIMNAMEPLATE    ":/Data/Sprites/Tim_NamePlate.png"
#define SKILLSPHERE     ":/Data/Sprites/Skill_Sphere.png"
#define ROUNDTIMER      ":/Data/Sprites/Round_Timer.png"

//EX SPRITE
#define GRASSLAND ":/Data/Sprites/BG.png"
#define FLOOR     ":/Data/Sprites/floor.png"

//DEBUG LAYER
#define RULER  ":/Data/Sprites/Ruler.png"
#define GRID1 ":/Data/Sprites/Grid-1.png"
#define DUMMY  ":/Data/Sprites/Dummy.png"
#define TARGET ":/Data/Sprites/Target.png"
#define GRAB ":/Data/Sprites/Grab.png"

#endif // SPRITELIST_H
