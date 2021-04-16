#include "objects.h"

render_object::render_object(int x, int y, QList<spriteframe> * spl, int si)
{
    setXY(x,y);
    sprite_list = spl;
    sprite_index = si;
    setSprite(sprite_list->at(sprite_index));
}

render_object::render_object(int x, int y, QList<spriteframe> * spl, int si, int z)
    {
        setXY(x,y);
        sprite_list = spl;
        sprite_index = si;
        setSprite(sprite_list->at(sprite_index));
        setZVal(z);
    }

render_object::render_object(int x, int y, qreal z,QList<spriteframe> * spl, int si)
    {
        setXY(x,y);
        sprite_list = spl;
        sprite_index = si;
        setSprite(sprite_list->at(sprite_index));
        setScale(z);
    }

render_object::render_object(int x, int y, qreal z,spriteframe sf)
    {
        setXY(x,y);
        sprite_list = NULL;
        sprite_index = 0;
        cursprite = sf;
        setSprite(sf);
        setScale(z);
    }

void render_object::init_Sprite(QList<spriteframe> * spl, int si)
{
    sprite_list = spl;
    sprite_index = si;
    if (sprite_list->size()==0){
        return;
    }
    cursprite = sprite_list[0].at(sprite_index);
    setSprite(cursprite);
}

void render_object::setX(int a)
{                   // Set X position
    x = a;
    sprite->setOffset(x,y);
}

void render_object::setY(int b)
{                   // Set Y position
    y = b;
    sprite->setOffset(x,y);
}

void render_object::setXY(int a, int b)
{
    // Set X and Y position
     x=a;
     y=b;
     sprite->setOffset(x,y);
}

void render_object::setSpotX(int a)
{
    spotX = a;
    x = (map_slot[spotY][spotX][0]/scale)-center_offset;
    y = (map_slot[spotY][spotX][1]/scale)-(center_offset*scale);
    sprite->setOffset(x,y);
}

void render_object::setSpotY(int b)
{
    spotY = b;
    x = (map_slot[spotY][spotX][0]/scale)-center_offset;
    y = (map_slot[spotY][spotX][1]/scale)-(center_offset*scale);
    sprite->setOffset(x,y);
}

void render_object::setSpotXY(int a, int b)
{
    spotX = a;
    spotY = b;
    x = (map_slot[spotY][spotX][0]/scale)-center_offset;
    y = (map_slot[spotY][spotX][1]/scale)-(center_offset*scale);
    sprite->setOffset(x,y);
}

void render_object::setZVal(int z)
{
    sprite->setZValue((qreal) z);
}

void render_object::setScale(qreal newscale)
{      // Scales the image
    scale = newscale;
    //sprite->pixmap().scaled(QSize(scale,scale));
    sprite->setScale(scale);
}

void render_object::setCenterOffset(int a)
{        // Sets the center
    center_offset=a;
}

void render_object::setSpriteSingle(QPixmap single)
{
    sprite->setPixmap(single);
}

void render_object::initSprite_List(QList<spriteframe> *sfl, int si)
{
    sprite_list = sfl;
    sprite_index = si;
    setSprite(sprite_list->at(sprite_index));
}

void render_object::setSprite(spriteframe newsprite)
{// Sets the sprite of player as newsprite
    dur_index = 0;
    cursprite = newsprite;
    sprite->setPixmap(QPixmap(cursprite.getSprite()));
}

int render_object::getPosX()
{
    return x;
}

int render_object::getPosY()
{
    return y;
}

int render_object::getSpotX()
{
    return spotX;
}

int render_object::getSpotY()
{
    return spotY;
}

int render_object::getZVal()
{
    return sprite->zValue();
}

qreal render_object::getScale()
{
    return scale;
}

int render_object::getCenterOffset()
{
    return center_offset;
}

QGraphicsPixmapItem*  render_object::getSprite()
{
    return sprite;
}

spriteframe render_object::getSpriteat(int si)
{
  return sprite_list->at(si);
}

spriteframe render_object::getSpriteFrame()
{
    return cursprite;
}

void render_object::update_sprite()
{
    if (cursprite.getDuration()!=0){
        dur_index++;
        if (dur_index >=cursprite.getDuration()){
          dur_index = 0;
          sprite_index=cursprite.get_Next_Index();
          cursprite = sprite_list[0].at(sprite_index);
          sprite->setPixmap(QPixmap(cursprite.getSprite()));
        }
    }

}

controllable_object::
controllable_object(QList<spriteframe> * spr_list,int spr_index,int x,int y,qreal scale,int c_of)
{
    initSprite_List(spr_list,spr_index);
    setCenterOffset(c_of);
     setScale(scale);
    setSpotXY(x,y);
}

void controllable_object::moveself(bool u, bool d , bool l, bool r){
    if (u && getSpotY()>0){
        setSprite(getSpriteat(2));
        setSpotY(getSpotY()-1);
    }
    if (d && getSpotY()<2){
        setSprite(getSpriteat(2));
        setSpotY(getSpotY()+1);
    }
    if (l && getSpotX()>0){
        setSprite(getSpriteat(5));
        setSpotX(getSpotX()-1);
    }
    if (r && getSpotX()<2){
        setSprite(getSpriteat(2));
        setSpotX(getSpotX()+1);
    }
}

void controllable_object::logic()
{
    update_sprite();
}

enemy_object::
enemy_object(QList<spriteframe> * spr_list,int spr_index,
             int x, int y,qreal scale,int cof)
{
    initSprite_List(spr_list,spr_index);
    setCenterOffset(cof);
    setScale(scale);
    setSpotXY(x,y);
}

bar_object::bar_object(){}

bar_object::bar_object(int x, int y, spriteframe spl)
{
    setXY(x,y);
    setSprite(spl);
}

bar_object::bar_object(int x, int y, qreal z, spriteframe spl)
{
    setXY(x,y);
    setScale(z);
    setSprite(spl);
}

void bar_object::logic()
{
    QPixmap temp = getSpriteFrame().getSprite();
    QPixmap newsprite = temp.copy(0,0,0,0);
    setSpriteSingle(newsprite);
    std::cout << "Bar logic" << std::endl;
}
