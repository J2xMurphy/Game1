#ifndef CTRLVARS_H
#define CTRLVARS_H

//TODO
#include <QTimer>
//Allows Dynamic setting of the controls


extern short map_slot[3][5][2];

extern int k_up;
extern int k_down;
extern int k_left;
extern int k_right;

extern int framerate;
extern QTimer * frametime;
extern int clist[4];

#endif // CTRLVARS_H

