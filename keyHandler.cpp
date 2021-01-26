#include "keyHandler.h"

void keyWatcher::logic(){
    for (cbtn &cur_btn: this->clist){
        cur_btn.tapped=0;
    }
}

void keyWatcher::btndef(int a,int b, int c, int d){
    clist[0].id=a;
    clist[1].id=b;
    clist[2].id=c;
    clist[3].id=d;
}

void keyWatcher::keyPressEvent(QKeyEvent * keypress)
{
    o = keypress->key();
    std::cout << "Key Pressed: " << keypress->key() << std::endl;
    for (cbtn& cb: clist){
//        std::cout << cb.id << " ";
        if (cb.id==keypress->key()){
 //           std::cout << "Recognized Press";
            cb.held=true;
            cb.tapped=true;
        }
    }
//    std:: cout << std::endl;
    emit keyPressed(o);
    return;
}

void keyWatcher::keyReleaseEvent(QKeyEvent * keypress)
{
    o = 0;
    for (cbtn& cb: clist){
        if (cb.id==keypress->key())
            cb.held=false;
    }
    //std::cout << "Key Released: " << keypress->key() << std::endl;
    return;
}

void keyWatcher::showKey(){
    std::cout << "OOP" << o << std::endl;
    return;
}

void keyWatcher::keyApply(){
    std::cout << clist[0].held
              << clist[1].held
              << clist[2].held
              << clist[3].held
              << std::endl;
    emit UDLDHeld(
            clist[0].held,
            clist[1].held,
            clist[2].held,
            clist[3].held);
}
