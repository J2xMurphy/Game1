#include "SpriteList.h"

//##Declarations###############################################################
spriteframe::spriteframe(){}

spriteframe::spriteframe(int duration ,QString img_path ,int next_index){
        init(duration,img_path,next_index);
}

spriteframe::spriteframe(QString img_path){
    sprite = img_path;
};

//##Setters####################################################################
void spriteframe::init(int duration,QString img_path,int next_index){
    this->duration = duration;
    sprite = img_path;
    this->next_index = next_index;
};

void spriteframe::setNextIndex(int next_index){
        this->next_index = next_index;
    }

//##Getters####################################################################
int spriteframe::get_Next_Index(){
    return next_index;
}

QString spriteframe::getSprite(){
    return sprite;
};

int spriteframe::getDuration(){
    return duration;
};

//#####DEPRECATED#####
//spriteframe::spriteframe(int duration,QString img_path ,spriteframe * next_frame){
//    init(duration,img_path,next_frame);
//}
//void spriteframe::init(int dur,QString img_path,spriteframe * next_frame){
//    duration = dur;
//    sprite = img_path;
//    next = next_frame;
//}
//  void spriteframe::setNext(spriteframe* next_frame){
//      next = next_frame;
//  };
//  spriteframe* spriteframe::getNext(){
//      return next;
//  };
