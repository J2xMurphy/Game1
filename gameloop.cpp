#include "gameloop.h"
#include "exc_data.cpp"
#include "QList"

controllable_object * player;//The player object
enemy_object * enemy;

QList<render_object *> objlist;

void gameloop::initialize(QGraphicsScene * newscene,QApplication * a)
{
    app = a;
    scene = newscene;// Import passed scene to local pointer

    // If debug is set, objlist is trackable in GDB
    if (debug) QList<render_object*> review = objlist;

    // Start all objects
    init_objects();
    init_input();
    init_player();
    init_enemy();
    init_logic();
}

bool gameloop::do_loop()
{
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

    for (int index = 0; index < objlist.size(); index++){
        objlist[index]->logic();
    }

    input->logic();
    return true;
}

void gameloop::init_input()
{
    clist[0] = {k_up};// Set internal up to up arrow
    clist[1] = {k_down};// Set internal down to down arrow
    clist[2] = {k_left};// Set internal left to left arrow
    clist[3] = {k_right};// Set internal right to right arrow

    input = new keyWatcher();// Create new key handler
    input->setFlag(QGraphicsItem::ItemIsFocusable);// Allow Input
    input->setFocus();// Set to handle input
    input->buttondef(clist[0],clist[1],clist[2],clist[3]);// apply inputs

    scene->addItem(input);// Add inputs to scene
    scene->setFocusItem(input);
}

void gameloop::init_objects()
{
    health_bars(&objlist);
    scene1(&objlist);
    if (debug) debug_layer(&objlist);
    skill_spheres(&objlist);
    timer(&objlist);

    // add all of the pulled render objects for the level to the scene
    for(int index = 0; index < objlist.size(); index++){
        objlist[index]->push_to_scene(scene);
    }

    group_object * go = new group_object;
    render_item * a = new render_item;
    render_item * b = new render_item;

    objlist.push_back(static_cast<render_object*>(go));

    a->setParent(go);
    a->setSprite(GRAB);
    a->setScale(3);
    a->setXY(250,250);

    b->setSprite(GRAB);
    b->setScale(2);
    b->setXY(500,500);
    go->add_Item(a);
    go->add_Item(b);
    go->push_to_scene(scene);
}

void gameloop::init_player()
{
    // Setting the character parameters, sprite dimensions and location
    QList<spriteframe> * playerspl = new QList<spriteframe>;// Sprite list for char
    Player_sprite_init(playerspl);// Populate sprite list
    player = new controllable_object(playerspl,0,1,1,2.0,36,72);// Create a player character
    player->push_to_scene(scene);
}

void gameloop::init_enemy()
{
    // Creating a test dummy with paraeters
    QList<spriteframe> * dummyspl = new QList<spriteframe>;
    dummy_sprite_init(dummyspl);
    enemy = new enemy_object(dummyspl,0,4,1,2,36,72);
    enemy->push_to_scene(scene);
}

void gameloop::init_logic()
{
    // This will call logic based on desired framerate
    frametime = new QTimer;//Initialize frame timer
    frametime->setInterval(1000/framerate);//Set based on framerate
    frametime->start();//Start the timer
    frametime->callOnTimeout(this, &gameloop::do_loop);//Exec on T/O
}

