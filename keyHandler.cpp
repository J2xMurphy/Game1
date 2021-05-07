#include "keyHandler.h"
//## Control_Button #####
control_button::control_button(int button_id){
    this->button_id = button_id;
}


//## Key_Watcher #######
void keyWatcher::logic(){
    for (control_button &cur_button: this->clist){
        cur_button.tapped=0;
    }
}

void keyWatcher::buttondef(int a,int b, int c, int d){
    clist[0].button_id=a;
    clist[1].button_id=b;
    clist[2].button_id=c;
    clist[3].button_id=d;
}

void keyWatcher::keyPressEvent(QKeyEvent * keypress)
{
    o = keypress->key();
    for (control_button& cb: clist){
        if (cb.button_id==keypress->key()){
            cb.held=true;
            cb.tapped=true;
        }
    }
    emit keyPressed(o);
    return;
}

void keyWatcher::keyReleaseEvent(QKeyEvent * keypress)
{
    o = 0;
    for (control_button& cb: clist){
        if (cb.button_id==keypress->key())
            cb.held=false;
    }
    return;
}

void keyWatcher::showKey(){
    return;
}

void keyWatcher::keyApply(){
    emit UDLDHeld(
            clist[0].held,
            clist[1].held,
            clist[2].held,
            clist[3].held);
}
