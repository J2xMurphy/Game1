#include "player.h"

void mainActor::move(bool u,bool d, bool l, bool r){
//    std::cout << key << std::endl;
    if (u){
        pRect->setPos(pRect->x(),pRect->y()-10);
    }
    if (d){
        pRect->setPos(pRect->x(),pRect->y()+10);
    }
    if (l){
        pRect->setPos(pRect->x()-10,pRect->y());
    }
    if (r){
        pRect->setPos(pRect->x()+10,pRect->y());
    }
}


void mainActor::moveSelf(int key){
//    std::cout << key << std::endl;
    if (key==1){
        pRect->setPos(pRect->x(),pRect->y()-10);
    }
    if (key==2){
        pRect->setPos(pRect->x(),pRect->y()+10);
    }
    if (key==3){
        pRect->setPos(pRect->x()-10,pRect->y());
    }
    if (key==4){
        pRect->setPos(pRect->x()+10,pRect->y());
    }
}
// Sets easier rectangle
void mainActor::setCenteredRect(int x, int y, int width, int height){
    pRect->setRect(x-(width/2),y-(height/2),width,height);
    return;
}

QGraphicsRectItem * mainActor::getRect(){
    return pRect;
}
