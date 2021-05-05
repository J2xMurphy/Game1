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
    objlist->push_back(new render_object(0,0,1,spr_create(GRASSLAND)));

    objlist->push_back(new render_object(0,315,1,spr_create(FLOOR)));

    objlist->push_back(new render_object(0,0,2,spr_create(RULER)));
}

void health_bars(QList<render_object*>* objlist){
    objlist->push_back(new static_object
                       (10,UI_HEIGHT+60,spr_create(BASEHEALTHBAR)));

    objlist->push_back(new bar_object
                       (30,UI_HEIGHT+65,spr_create(FRONTHEALTHBAR)));

    objlist->push_back(new static_object
                       (12,UI_HEIGHT+130,0.6,1.0,spr_create(BASEHEALTHBAR)));

    objlist->push_back(new bar_object
                       (24,UI_HEIGHT+133,0.6,spr_create(FRONTSPECIALBAR)));

    objlist->push_back(new static_object
                       (950,UI_HEIGHT+60,spr_create(BASEHEALTHBAR)));

    objlist->push_back(new bar_object
                       (970,UI_HEIGHT+65,spr_create(FRONTHEALTHBAR)));

    objlist->push_back(new static_object
                       (1204,UI_HEIGHT+130,0.6,1.0,spr_create(BASEHEALTHBAR)));

    objlist->push_back(new bar_object
                       (1216,UI_HEIGHT+133,0.6,spr_create(FRONTSPECIALBAR)));

    if (Player1 == "Tim"){
                objlist->push_back(new render_object
                                   (0,UI_HEIGHT,1,spr_create(TIMNAMEPLATE),101.0));
                objlist->push_back(new text_object
                                   (100,UI_HEIGHT,255,"Tim",QFont("times",40)));
    }

}

void floor_targets(QList<render_object*>* objlist)
{
    for (int a = 0; a < 3; a++)
    {
        for (int b = 0; b < 5; b++)
        {
            static_object * target =
                    new static_object(map_slot[a][b][0],map_slot[a][b][1],
                    1,101,spr_create(TARGET));
            target->setCenterOffset(50,50);
            objlist->append(target);
        }
    }
}

void skill_spheres(QList<render_object*>* objlist)
{

    for (int a = 0; a < 4; a++)
    {
        for (int b = 0; b < 2; b++)
        {
            static_object * target = new static_object(
                        (a*35)+100,(b*30)+230+UI_HEIGHT,
                        1,102,spr_create(SKILLSPHERE));
            target->setCenterOffset(50,50);
            objlist->append(target);
        }
    }
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
