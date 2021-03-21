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
//    scene1(&objlist);
//    health_bars(&objlist);

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
    input->btndef(clist[0],clist[1],clist[2],clist[3]);// apply inputs

    // add all of the pulled render objects for the level to the scene
//    for(render_object curobj:objlist){
//        scene->addItem(curobj.getSprite());
//    }

    // Setting the character parameters, sprite dimensions and location
    std::cout << "1" << std::endl;
    player = new controllable_object;
    std::cout << "2" << std::endl;
    QList<spriteframe> * playerspl = new QList<spriteframe>;
    std::cout << "3" << std::endl;
    Player_sprite_init(playerspl);
    std::cout << "4" << std::endl;
    player->init_Sprite(playerspl,0);
    std::cout << "5" << std::endl;
    player->setCenterOffset(36);
    std::cout << "6" << std::endl;
    player->setScale(2.0);
    std::cout << "7" << std::endl;
    player->setSpotXY(1,0);

    // Creating a test dummy with paraeters
//    enemy = new enemy_object;
//    enemy->setSprite(dummy);
//    enemy->setCenterOffset(36);
//    enemy->setScale(2.0);
//    enemy->setSpotXY(4,1);

std::cout << "Getting Sprite " << std::endl;
    scene->addItem(player->getSprite());// Add player image to scene
//    scene->addItem(enemy->getSprite());
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
//    enemy->logic();

    for (render_object curobj:(objlist)){
        curobj.logic();
    }
    input->logic();
    return true;
}

void controllable_object::moveself(bool u, bool d , bool l, bool r){
    if (u && getSpotY()>0){
        setSprite(getSpriteat(3));
        setSpotY(getSpotY()-1);
    }
    if (d && getSpotY()<2){
        setSprite(getSpriteat(3));
        setSpotY(getSpotY()+1);
    }
    if (l && getSpotX()>0){
        setSprite(getSpriteat(6));
        setSpotX(getSpotX()-1);
    }
    if (r && getSpotX()<2){
        setSprite(getSpriteat(3));
        setSpotX(getSpotX()+1);
    }
//    std::cout << getPosX() << "," << getPosY() <<std::endl;
//    std::cout << getSpotX() << "," << getSpotY() <<std::endl;
}

void render_object::setSpotX(int a){    // Set X position
    spotX = a;
    x = (map_slot[spotY][spotX][0]/scale)-center_offset;
    y = (map_slot[spotY][spotX][1]/scale)-(center_offset*scale);
    sprite->setOffset(x,y);
};
void render_object::setSpotY(int b){    // Set Y position
    spotY = b;
    x = (map_slot[spotY][spotX][0]/scale)-center_offset;
    y = (map_slot[spotY][spotX][1]/scale)-(center_offset*scale);
    sprite->setOffset(x,y);
};
void render_object::setSpotXY(int a, int b){
    spotX = a;
    spotY = b;
    x = (map_slot[spotY][spotX][0]/scale)-center_offset;
    y = (map_slot[spotY][spotX][1]/scale)-(center_offset*scale);
    sprite->setOffset(x,y);
};


void bar_object::logic() {
    QPixmap temp = getSpriteFrame().getSprite();
    QPixmap newsprite = temp.copy(0,0,0,0);
    setSpriteSingle(newsprite);
    std::cout << "Bar logic" << std::endl;
};
