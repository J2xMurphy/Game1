#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);// Create Application
    QGraphicsScene * scene = new QGraphicsScene();// create a scene
    QGraphicsView * view = new QGraphicsView(scene);// add a view

    view->setFixedSize(1366,768);// View Parameters
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->verticalScrollBar();


    sceneRectInit(scene);// Initialize screen space
    scene->setSceneRect(0,0,1600,900);


    view->scale(view->width()/scene->width(),view->height()/scene->height());

    gameloop * mainloop = new gameloop();
    mainloop->initialize(scene,&a);

    a.setApplicationName("Vertex");

    view->show(); // show the rendered viewport
    return a.exec();
}

// Sets screen parameters
void sceneRectInit(QGraphicsScene * scene){
    scene->setSceneRect(viewport_x,viewport_y,
                        window_width,window_height);
    return;
}

