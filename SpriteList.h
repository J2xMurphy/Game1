#ifndef SPRITELIST_H
#define SPRITELIST_H

#include <QPixmap>
#include <QGraphicsPixmapItem>

class spriteframe{
    int duration = 1;
    QString sprite = ":/Sprites/circle.png";
    spriteframe * next = NULL;
public:
    //spriteframe(int duration=1,QString path=":/Sprites/circle.png");
    spriteframe(){}
    spriteframe(int a ,QString b ,spriteframe * c){
        init(a,b,c);
    }

    void init(int dur,QString path,spriteframe * nxt){
        duration = dur;
        sprite = path;
        next = nxt;

    };
    void setNext(
            spriteframe* nxt){next = nxt;
    };
    spriteframe* getNext(){
        return next;
    };

    int getDuration(){
        return duration;
    };

    QString getSprite(){
        return sprite;
    };
};

#define IDLE1_IMG ":/Sprites/Idle1.png"
#define IDLE2_IMG ":/Sprites/Idle2.png"

#define FORWARD_IMG1 ":/Sprites/Forward1_Test.png"
#define FORWARD_IMG2 ":/Sprites/Forward2_Test.png"
#define FORWARD_IMG3 ":/Sprites/Forward3_Test.png"

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