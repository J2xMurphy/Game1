#include "gameloop.h"
#include "exc_data.cpp"
#include "QList"

controllable_object * player;//The player object
enemy_object * enemy;

QList<render_object *> objlist;

void gameloop::initialize(QGraphicsScene * newscene,QApplication * a){
//    S_init();
    scene1(&objlist);
    health_bars(&objlist);

    clist[0] = {k_up};// Set internal up to up arrow
    clist[1] = {k_down};// Set internal down to down arrow
    clist[2] = {k_left};// Set internal left to left arrow
    clist[3] = {k_right};// Set internal right to right arrow

    app = a;
    scene = newscene;// Import passed scene to local pointer
    scene->setFocusItem(input);

    input = new keyWatcher();// Create new key handler
    input->setFlag(QGraphicsItem::ItemIsFocusable);// Allow Input
    input->setFocus();// Set to handle input
    scene->addItem(input);// Add inputs to scene
    input->buttondef(clist[0],clist[1],clist[2],clist[3]);// apply inputs

    // add all of the pulled render objects for the level to the scene
    for(int index = 0; index < objlist.size(); index++){
        scene->addItem(objlist[index]->getSprite());
    }

    // Setting the character parameters, sprite dimensions and location
    QList<spriteframe> * playerspl = new QList<spriteframe>;// Sprite list for char
    Player_sprite_init(playerspl);// Populate sprite list
    player = new controllable_object(playerspl,0,1,1,2.0,36);// Create a player character

    // Creating a test dummy with paraeters
    QList<spriteframe> * dummyspl = new QList<spriteframe>;
    dummy_sprite_init(dummyspl);
    enemy = new enemy_object(dummyspl,0,4,1,2.0,36);

    scene->addItem(player->getSprite());// Add player image to scene
    scene->addItem(enemy->getSprite());

    // This will call logic based on desired framerate
    frametime = new QTimer;//Initialize frame timer
    frametime->setInterval(1000/framerate);//Set based on framerate
    frametime->start();//Start the timer
    frametime->callOnTimeout(this, &gameloop::do_loop);//Exec on T/O
}

bool gameloop::do_loop(){
    if (input->hasFocus()==0){
        input->setFocus();
    }
    player->moveself(
            input->clist[0].tapped,
            input->clist[1].tapped,
            input->clist[2].tapped,
            input->clist[3].tapped);
    player->logic();
    enemy->logic();

//    for (render_object curobj:(objlist)){
//        curobj.logic();
//    }
    for (int index = 0; index < objlist.size(); index++){
        objlist[index]->logic();
    }

    input->logic();
    return true;
}
