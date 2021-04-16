#include "gameloop.h"
#include "exc_data.cpp"
#include "QList"

controllable_object * player;//The player object
enemy_object * enemy;

int framerate;
QTimer * frametime;
int clist [4];
QList<render_object> objlist;



void gameloop::initialize(QGraphicsScene * newscene,QApplication * a){
//    S_init();
    scene1(&objlist);
    health_bars(&objlist);

    framerate = 60;// Set the game's desired framerate
    clist[0] = {16777235};// Set internal up to up arrow
    clist[1] = {16777237};// Set internal down to down arrow
    clist[2] = {16777234};// Set internal left to left arrow
    clist[3] = {16777236};// Set internal right to right arrow

    app = a;
    scene = newscene;// Import passed scene to local pointer
    scene->setFocusItem(input);

    input = new keyWatcher();// Create new key handler
    input->setFlag(QGraphicsItem::ItemIsFocusable);// Allow Input
    input->setFocus();// Set to handle input
    scene->addItem(input);// Add inputs to scene
    input->buttondef(clist[0],clist[1],clist[2],clist[3]);// apply inputs

    // add all of the pulled render objects for the level to the scene
    for(render_object curobj:objlist){
        scene->addItem(curobj.getSprite());
    }

    // Setting the character parameters, sprite dimensions and location
    QList<spriteframe> * playerspl = new QList<spriteframe>;// Sprite list for char
    Player_sprite_init(playerspl);// Populate sprite list
    player = new controllable_object(playerspl,0,1,1,2.0,36);// Create a player character

    // Creating a test dummy with paraeters
    QList<spriteframe> * dummyspl = new QList<spriteframe>;
    dummy_sprite_init(dummyspl);
    enemy = new enemy_object(dummyspl,0,4,1,2.0,36);

std::cout << "Getting Sprite " << std::endl;
    scene->addItem(player->getSprite());// Add player image to scene
    scene->addItem(enemy->getSprite());
std::cout << "... got it!" << std::endl;

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
//    std::cout << input->hasFocus() << std::endl;
    player->moveself(
            input->clist[0].tapped,
            input->clist[1].tapped,
            input->clist[2].tapped,
            input->clist[3].tapped);
    player->logic();
    enemy->logic();

    for (render_object curobj:(objlist)){
        curobj.logic();
    }
    input->logic();
    return true;
}
