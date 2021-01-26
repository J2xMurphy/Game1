#ifndef MAIN_H
#define MAIN_H

#include "mainwindow.h"
#include "gameloop.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>
#include <QObject>


void sceneRectInit(QGraphicsScene * scene);
void ctrlVarInit();

int window_width = 1595;
int window_height = 895;
int viewport_x = 0;
int viewport_y = 0;


#endif // MAIN_H
