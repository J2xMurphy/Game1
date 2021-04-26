#ifndef MAIN_H
#define MAIN_H

#include "mainwindow.h"
#include "gameloop.h"
#include "CTRLVARS.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <iostream>
#include <QObject>

class No_ScrollQGraphicsView : public QGraphicsView
{
public:
    No_ScrollQGraphicsView(QWidget * parent = nullptr);
    No_ScrollQGraphicsView(QGraphicsScene * scene, QWidget * parent = nullptr);

protected:
    virtual void wheelEvent(QWheelEvent * event);
};

void sceneRectInit(QGraphicsScene * scene);
void ctrlVarInit();

#endif // MAIN_H
