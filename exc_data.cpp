#include "SpriteList.h"
#include "gameloop.h"
#include "CTRLVARS.h"

#include <list>
#include "QList"

spriteframe * ruler = new spriteframe;
spriteframe * dummy = new spriteframe;
spriteframe * flor = new spriteframe;


void Player_sprite_init(QList<spriteframe> * sprlist){
    sprite_appender(
      sprlist,
     {spr_create(10,IDLE1_IMG,1),     //0
      spr_create(10,IDLE2_IMG,0),     //1
      spr_create(5,FORWARD_IMG1,3),  //2
      spr_create(5,FORWARD_IMG2,4),  //3
      spr_create(5,FORWARD_IMG3,0),  //4
      spr_create(5,BACKWARDS_IMG1,6),//5
      spr_create(5,BACKWARDS_IMG2,7),//6
      spr_create(5,BACKWARDS_IMG3,0) //7
      }); //8});
}

void dummy_sprite_init(QList<spriteframe> * sprlist){
    sprite_appender(sprlist,{spr_create(0,DUMMY,0)});
}

void scene1(QList<render_object>* objlist){
    // Scene 1's Object list--------------------
    render_object bg_obj(0,0,1,spr_create(GRASSLAND));
    objlist->push_back(bg_obj);

    render_object floor_obj(0,315,1,spr_create(FLOOR));
    objlist->push_back(floor_obj);

    render_object ruler_obj(0,0,2,spr_create(RULER));
    objlist->push_back(ruler_obj);

}

void health_bars(QList<render_object>* objlist){
    bar_object basehealthbar1(10,10,spr_create(BASEHEALTHBAR));
    objlist->push_back(basehealthbar1);

    bar_object fronthealthbar1(30,20,spr_create(FRONTHEALTHBAR));
    objlist->push_back(fronthealthbar1);

    bar_object basespecialbar1(12,170,0.60,spr_create(BASEHEALTHBAR));
    objlist->push_back(basespecialbar1);

    bar_object frontspecialbar1(basespecialbar1.getPosX()+20,
                                basespecialbar1.getPosY()+7,
                                basespecialbar1.getScale(),
                                spr_create(FRONTSPECIALBAR));
    objlist->push_back(frontspecialbar1);

    bar_object basehealthbar2(950,10,spr_create(BASEHEALTHBAR));
    objlist->push_back(basehealthbar2);

    bar_object fronthealthbar2(970,17,spr_create(FRONTHEALTHBAR));
    objlist->push_back(fronthealthbar2);

    bar_object basespecialbar2(2015,170,0.6,spr_create(BASEHEALTHBAR));
    objlist->push_back(basespecialbar2);

    bar_object frontspecialbar2(basespecialbar2.getPosX()+20,
                                basespecialbar2.getPosY()+7,
                                basespecialbar2.getScale(),
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
    std::cout << img.toStdString() << std::endl;
    return tmp;
};

spriteframe spr_create(int dur,QString img,int next){
    spriteframe tmp(dur,img,next);
    std::cout << img.toStdString() << std::endl;
    return tmp;
};
