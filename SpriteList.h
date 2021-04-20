#ifndef SPRITELIST_H
#define SPRITELIST_H

#include <QPixmap>
#include <iostream>
#include <QGraphicsPixmapItem>

//Spriteframe is essentailly a linked list that has data of:
//  [1] when to swap with next image/link
//  [2] the image that is to be displayed currently
//  [3] the preferred next spriteframe to be set if animated externally
class spriteframe{
private:
    int duration = 0;
    QString sprite = ":/Sprites/circle.png";
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


//#####DEPRECATED#####
// Takes in sprite duration, sprite location, and next spriteframe
//    spriteframe * next = NULL;
//  spriteframe(int duration,QString img_path ,spriteframe * next_frame);
//  void init(int duration,QString img_path,spriteframe * next_frame);
//  void setNext(spriteframe* nxt);
//  spriteframe* getNext();
};

spriteframe spr_create(QString);
spriteframe spr_create(int,QString,int);
void sprite_appender(QList<spriteframe>*,QList<spriteframe>);


//#############################################################################
//LIST OF ALL THE SPRITES IN THE GAME
//#############################################################################

#define IDLE1_IMG ":/Sprites/Idle1.png"
#define IDLE2_IMG ":/Sprites/Idle2.png"

#define FORWARD_IMG1 ":/Sprites/Forward1_Test.png"
#define FORWARD_IMG2 ":/Sprites/Forward2_Test.png"
#define FORWARD_IMG3 ":/Sprites/Forward3_Test.png"

//#define FORWARD_IMG1 ":/Sprites/Test2.png"
//#define FORWARD_IMG2 ":/Sprites/Test2.png"
//#define FORWARD_IMG3 ":/Sprites/Test2.png"



#define BACKWARDS_IMG1 ":/Sprites/Backwards1_Test.png"
#define BACKWARDS_IMG2 ":/Sprites/Backwards2_Test.png"
#define BACKWARDS_IMG3 ":/Sprites/Backwards3_Test.png"

#define RULER ":/Sprites/Ruler.png"
#define DUMMY ":/Sprites/Dummy.png"

#define BASEHEALTHBAR   ":/Sprites/Base_hp.png"
#define FRONTHEALTHBAR  ":/Sprites/front_hp.png"
#define FRONTSPECIALBAR ":/Sprites/front_mp.png"

#define GRASSLAND ":/Sprites/BG.png"
#define FLOOR ":/Sprites/floor.png"

#endif // SPRITELIST_H
