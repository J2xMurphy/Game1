#include "CTRLVARS.h"

short map_slot[3][5][2] =
{
    {  {322,394}, {563,394}, {805,394}, {1038,394}, {1279,394} },
    {  {278,553}, {541,553}, {806,553}, {1059,553}, {1322,553} },
    {  {225,746}, {515,746}, {807,746}, {1084,746}, {1375,746} }
};

int k_up    = 16777235;
int k_down  = 16777237;
int k_left  = 16777234;
int k_right = 16777236;

int framerate = 60;// Set the game's desired framerate
QTimer * frametime;
int clist[4];