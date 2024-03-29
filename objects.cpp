#include "objects.h"
//RENDER ITEM
//#############################################################################
render_item::render_item(){
    x = 0;
    y = 0;
    sprite = new QGraphicsPixmapItem;
    sprite->setPixmap(QString(TARGET));
}

render_item::render_item(sprite_dump parent){
//    x = new int(100);
//    y = new int(100);


    sprite = new QGraphicsPixmapItem;
    sprite->setX(x);
    sprite->setY(y);
    sprite->setPixmap(QString(TIMNAMEPLATE));

}

void render_item::setXY(int a, int b){
    x = a;
    y = b;
    if (parent != NULL){
        sprite->setX(parent->getPosX()+x);
        sprite->setY(parent->getPosY()+y);
//        qDebug() << parent->x << parent->getPosY();
    }
    else{
        sprite->setX(x);
        sprite->setY(y);
    }
    sprite->setZValue(100);
}

void render_item::setParent(render_object * mom){
    parent = mom;
    setXY(0,0);
}

void render_item::setSprite(QString path){
    sprite->setPixmap(path);
}

QGraphicsPixmapItem * render_item::getSprite()
{
    return sprite;
}

void render_item::setScale(qreal scale)
{
    sprite->setScale(scale);
}

void render_item::logic(bool parent_changed)
{
    if (parent_changed)
    {
        setXY(x,y);
    }
    else{
        return;
    }
}

//RENDER OBJECTS
//#############################################################################
render_object::render_object()
{
    sprite = new QGraphicsPixmapItem;
}

render_object::render_object(int x, int y, QList<spriteframe> * spl, int si)
{
    sprite = new QGraphicsPixmapItem;
    setXY(x,y);
    sprite_list = spl;
    sprite_index = si;
    setSprite(sprite_list->at(sprite_index));
}

render_object::render_object(int x, int y, QList<spriteframe> * spl, int si, int z)
    {
        sprite = new QGraphicsPixmapItem;
        setXY(x,y);
        sprite_list = spl;
        sprite_index = si;
        setSprite(sprite_list->at(sprite_index));
        setZVal(z);
    }

render_object::render_object(int x, int y, qreal s,QList<spriteframe> * spl, int si)
    {
        sprite = new QGraphicsPixmapItem;
        setScale(s);
        setXY(x,y);
        sprite_list = spl;
        sprite_index = si;
        setSprite(sprite_list->at(sprite_index));
    }

render_object::render_object(int x, int y, qreal s,spriteframe sf,qreal z)
    {
        sprite = new QGraphicsPixmapItem;
        setZVal(z);
        setScale(s);
        setXY(x,y);
        sprite_list = NULL;
        sprite_index = 0;
        cursprite = sf;
        setSprite(sf);
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
{
    // Set X position
    x = a;
    sprite->setX(x-center_offset_x);
}

void render_object::setY(int b)
{
    // Set Y position
    y = b;
    sprite->setY(y-center_offset_y);
}

void render_object::setXY(int a, int b)
{
    // Set X and Y position
     setX(a);
     setY(b);
}

void render_object::setSpotX(int a)
{
    spotX = a;
    x = (map_slot[spotY][spotX][0]-center_offset_x);
    y = (map_slot[spotY][spotX][1]-center_offset_y);
    sprite->setX(x);
    sprite->setY(y);
}

void render_object::setSpotY(int b)
{
    spotY = b;
    x = (map_slot[spotY][spotX][0]-center_offset_x);
    y = (map_slot[spotY][spotX][1]-center_offset_y);
    sprite->setX(x);
    sprite->setY(y);
}

void render_object::setSpotXY(int a, int b)
{
    setSpotX(a);
    setSpotY(b);
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
    center_offset_x = center_offset_x*scale;
    center_offset_y = center_offset_y*scale;
    setX(x);
    setY(y);
}

void render_object::setCenterOffset(int a, int b)
{
    // Sets the center
    center_offset_x=a*scale;
    center_offset_y=b*scale;
    setX(x);
    setY(y);
}

void render_object::setSpriteSingle(QPixmap single)
{
    static_cast<QGraphicsPixmapItem*>(sprite)->setPixmap(single);
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
    static_cast<QGraphicsPixmapItem*>(sprite)->setPixmap(QPixmap(cursprite.getSprite()));
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

sprite_dump render_object::getGenes()
{
    return {&x,&y};
}

qreal render_object::getScale()
{
    return scale;
}

int render_object::getCenterOffsetX()
{
    return center_offset_x;
}

int render_object::getCenterOffsetY()
{
    return center_offset_y;
}

QGraphicsItem * render_object::getSprite()
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

void render_object::push_to_scene(QGraphicsScene* scene){
    scene->addItem(getSprite());
}

void render_object::update_sprite()
{
    if (cursprite.getDuration()!=0){
        dur_index++;
        if (dur_index >=cursprite.getDuration()){
          dur_index = 0;
          sprite_index=cursprite.get_Next_Index();
          cursprite = sprite_list[0].at(sprite_index);
          static_cast<QGraphicsPixmapItem*>(sprite)->setPixmap(QPixmap(cursprite.getSprite()));
        }
    }

}

void render_object::logic()
{
    update_sprite();
}

// CONTROLLABLE OBJECTS
//#############################################################################

controllable_object::
controllable_object(QList<spriteframe> * spr_list,int spr_index,int x,int y,
                    qreal scale,int c_ofx= 0, int c_ofy = 0)
{
    sprite = new QGraphicsPixmapItem;
    initSprite_List(spr_list,spr_index);
    setCenterOffset(c_ofx,c_ofy);
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

void controllable_object::logic(){
    update_sprite();
}

// ENEMY OBJECTS
//#############################################################################

enemy_object::
enemy_object(QList<spriteframe> * spr_list,int spr_index,
             int x, int y,qreal scale,int c_ofx = 0, int c_ofy = 0)
{
    sprite = new QGraphicsPixmapItem;
    initSprite_List(spr_list,spr_index);
    setCenterOffset(c_ofx,c_ofy);
    setScale(scale);
    setSpotXY(x,y);
}

void enemy_object::logic()
{
    return;
}

//BAR OBJECTS
//#############################################################################

bar_object::bar_object()
{
    sprite = new QGraphicsPixmapItem;
}

bar_object::bar_object(int x, int y, spriteframe spl)
{
    sprite = new QGraphicsPixmapItem;
    setZVal(100);
    setXY(x,y);
    setSprite(spl);
}

bar_object::bar_object(int x, int y, qreal z, spriteframe spl)
{
    sprite = new QGraphicsPixmapItem;
    setScale(z);
    setZVal(100);
    setXY(x,y);
    setSprite(spl);
}

void bar_object::logic()
{
//    QPixmap temp = getSpriteFrame().getSprite();
//    float health_percent = curhealth;
//    health_percent /= maxhealth;
//    QPixmap newsprite = temp.copy(0,0,temp.width()*health_percent,temp.height());
//    setSpriteSingle(newsprite);
}

//STATIC OBJECTS
//#############################################################################

static_object::static_object()
{
    sprite = new QGraphicsPixmapItem;
}

static_object::static_object(int x, int y, spriteframe spl)
{
    sprite = new QGraphicsPixmapItem;
    setZVal(100);
    setXY(x,y);
    setSprite(spl);
}

static_object::static_object(int x, int y, qreal z,qreal depth, spriteframe spl)
{
    sprite = new QGraphicsPixmapItem;
    setScale(z);
    setZVal(depth);
    setXY(x,y);
    setSprite(spl);
}

//TEXT OBJECTS
//#############################################################################
// TIL::
// Make sure to use pointers correctly in type casting
// Sprite is a pointer, so be sure not to confuse it with a &QGraphicsTextItem
text_object::text_object
(int x, int y, qreal depth, QString text, QFont font)
{
    sprite = new QGraphicsTextItem;
    static_cast<QGraphicsTextItem*>(sprite)->setFont(font);
    setZVal(depth);
    setX(x);
    setY(y);
    setText(text);
}

void text_object::setText(QString text)
{
    static_cast<QGraphicsTextItem*>(sprite)->setPlainText(text);
}

void text_object::setFont(QFont font)
{
    static_cast<QGraphicsTextItem*>(sprite)->setFont(font);
}

QString text_object::getText()
{
    return static_cast<QGraphicsTextItem*>(sprite)->toPlainText();
}

QFont text_object::getFont()
{
    return static_cast<QGraphicsTextItem>(sprite).font();
}

void text_object::logic()
{
}

//GROUP OBJECTS
//#############################################################################
group_object::group_object(){
    items = 0;
    x = 6;
    y = 0;
}

void group_object::setXY(int a, int b)
{
    update_children = true;
    x = a;
    y = b;
}

void group_object::add_Item(render_item * nItem){
    R_items.push_back(nItem);
    items++;
}

void group_object::push_to_scene(QGraphicsScene * scene){
    for(int index = 0;index < R_items.size(); index++){
        scene->addItem(R_items[index]->getSprite());
    }
}

void group_object::logic()
{
    setXY(x+1,y);
    for(int index = 0;index < R_items.size(); index++){
        R_items[index]->logic(update_children);
    }
    update_children = false;
//    std::cout << x << std::endl;
}
