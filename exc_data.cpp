#include "SpriteList.h"
#include "gameloop.h"
#include "CTRLVARS.h"

#include <list>
#include "QList"

void Player_sprite_init(QList<spriteframe> * sprlist){
    sprite_appender(
      sprlist,
     {spr_create(10,IDLE1_IMG,1),     //0
      spr_create(10,IDLE2_IMG,0),     //1
      spr_create(2,FORWARD_IMG1,3),  //2
      spr_create(2,FORWARD_IMG2,4),  //3
      spr_create(2,FORWARD_IMG3,0),  //4
      spr_create(5,BACKWARDS_IMG1,6),//5
      spr_create(5,BACKWARDS_IMG2,7),//6
      spr_create(5,BACKWARDS_IMG3,0) //7
      }); //8});
}

void dummy_sprite_init(QList<spriteframe> * sprlist){
    sprite_appender(sprlist,{spr_create(0,DUMMY,0)});
}

void scene1(QList<render_object*>* objlist){
    // Scene 1's Object list--------------------
    render_object * bg_obj = new render_object(0,0,1,spr_create(GRASSLAND));
    objlist->push_back(bg_obj);

    render_object * floor_obj = new render_object(0,315,1,spr_create(FLOOR));
    objlist->push_back(floor_obj);

    render_object * ruler_obj = new render_object(0,0,2,spr_create(RULER));
    objlist->push_back(ruler_obj);

}

void health_bars(QList<render_object*>* objlist){
    bar_object * basehealthbar1 = new bar_object(10,10,spr_create(BASEHEALTHBAR));
    objlist->push_back(basehealthbar1);

    bar_object * fronthealthbar1 = new bar_object(30,20,spr_create(FRONTHEALTHBAR));
    objlist->push_back(fronthealthbar1);

    bar_object * basespecialbar1 = new bar_object(12,170,0.60,spr_create(BASEHEALTHBAR));
    objlist->push_back(basespecialbar1);

    bar_object * frontspecialbar1 = new bar_object(
                                basespecialbar1->getPosX()+20,
                                basespecialbar1->getPosY()+7,
                                basespecialbar1->getScale(),
                                spr_create(FRONTSPECIALBAR));
    objlist->push_back(frontspecialbar1);

    bar_object * basehealthbar2 = new bar_object(950,10,spr_create(BASEHEALTHBAR));
    objlist->push_back(basehealthbar2);

    bar_object * fronthealthbar2 = new bar_object(970,17,spr_create(FRONTHEALTHBAR));
    objlist->push_back(fronthealthbar2);

    bar_object * basespecialbar2 = new bar_object(2015,170,0.6,spr_create(BASEHEALTHBAR));
    objlist->push_back(basespecialbar2);

    bar_object * frontspecialbar2 = new bar_object(
                                basespecialbar2->getPosX()+20,
                                basespecialbar2->getPosY()+7,
                                basespecialbar2->getScale(),
                                spr_create(FRONTSPECIALBAR));
    objlist->push_back(frontspecialbar2);

}

void sprite_appender(QList<spriteframe> * enlist,QList<spriteframe> sfl){
    for (spriteframe sf:(sfl)){
        enlist->append(sf);
    }
};

spriteframe spr_create(QString img){
    spriteframe tmp(0,img,0);
    return tmp;
};

spriteframe spr_create(int dur,QString img,int next){
    spriteframe tmp(dur,img,next);
    return tmp;
};
