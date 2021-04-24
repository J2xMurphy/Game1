#ifndef CTRLVARS_H
#define CTRLVARS_H

//TODO
#include <QTimer>
//Allows Dynamic setting of the controls

extern int window_width;
extern int window_height;
extern int viewport_x;
extern int viewport_y;

extern short map_slot[3][5][2];

extern int k_up;
extern int k_down;
extern int k_left;
extern int k_right;

extern int framerate;
extern QTimer * frametime;
extern int clist[4];

extern int UI_HEIGHT;

extern QString Player1;

#endif // CTRLVARS_H

