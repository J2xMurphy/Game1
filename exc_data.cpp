#include "SpriteList.h"
#include "gameloop.h"
#include <list>
#include "QList"

spriteframe * player_idle1 = new spriteframe;
spriteframe * player_idle2 = new spriteframe;

spriteframe * player_forward1 = new spriteframe;
spriteframe * player_forward2 = new spriteframe;
spriteframe * player_forward3 = new spriteframe;

spriteframe * player_backwards1 = new spriteframe;
spriteframe * player_backwards2 = new spriteframe;
spriteframe * player_backwards3 = new spriteframe;

spriteframe * ruler = new spriteframe;
spriteframe * dummy = new spriteframe;
spriteframe * flor = new spriteframe;

spriteframe * base_health_bar = new spriteframe;
spriteframe * front_health_bar = new spriteframe;
spriteframe * front_special_bar = new spriteframe;

spriteframe * grassland = new spriteframe;

short map_slot[3][5][2] = {
    {  {322,394}, {563,394}, {805,394}, {1038,394}, {1279,394} },
    {  {278,553}, {541,553}, {806,553}, {1059,553}, {1322,553} },
    {  {225,746}, {515,746}, {807,746}, {1084,746}, {1375,746} }};

void S_init(){
    player_idle1->init(10,IDLE1_IMG,player_idle2);
    player_idle2->init(10,IDLE2_IMG,player_idle1);

    player_forward1->init(5,FORWARD_IMG1,player_forward2);
    player_forward2->init(5,FORWARD_IMG2,player_forward3);
    player_forward3->init(5,FORWARD_IMG3,player_idle1);

    player_backwards1->init(5,BACKWARDS_IMG1,player_backwards2);
    player_backwards2->init(5,BACKWARDS_IMG2,player_backwards3);
    player_backwards3->init(5,BACKWARDS_IMG3,player_idle1);

    ruler->init(0,RULER,ruler);
    dummy->init(0,DUMMY,dummy);
    flor->init(0,FLOOR,flor);

    base_health_bar->init(0,BASEHEALTHBAR,base_health_bar);
    front_health_bar->init(0,FRONTHEALTHBAR,front_health_bar);
    front_special_bar->init(0,FRONTSPECIALBAR,front_special_bar);

    grassland->init(0,GRASSLAND,grassland);
}

void scene1(QList<render_object>* objlist){
    render_object bg_obj(0,0,grassland,-10);
    objlist->push_back(bg_obj);

    render_object floor_obj(0,315,flor);
    objlist->push_back(floor_obj);

    render_object ruler_obj(0,0,2,ruler);
    objlist->push_back(ruler_obj);

}

void health_bars(QList<render_object>* objlist){
    bar_object basehealthbar1(10,10,base_health_bar);
    objlist->push_back(basehealthbar1);

    bar_object fronthealthbar1(30,20,front_health_bar);
    objlist->push_back(fronthealthbar1);

    bar_object basespecialbar1(12,170,0.60,base_health_bar);
    objlist->push_back(basespecialbar1);

    bar_object frontspecialbar1(basespecialbar1.getPosX()+20,
                                basespecialbar1.getPosY()+7,
                                basespecialbar1.getScale(),
                                front_special_bar);
    objlist->push_back(frontspecialbar1);

    bar_object basehealthbar2(950,10,base_health_bar);
    objlist->push_back(basehealthbar2);

    bar_object fronthealthbar2(970,17,front_health_bar);
    objlist->push_back(fronthealthbar2);

    bar_object basespecialbar2(2015,170,0.6,base_health_bar);
    objlist->push_back(basespecialbar2);

    bar_object frontspecialbar2(basespecialbar2.getPosX()+20,
                                basespecialbar2.getPosY()+7,
                                basespecialbar2.getScale(),
                                front_special_bar);
    objlist->push_back(frontspecialbar2);

}
