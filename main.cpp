#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);// Create Application
    QGraphicsScene * scene = new QGraphicsScene();// create a scene
    No_ScrollQGraphicsView * view = new No_ScrollQGraphicsView(scene);// add a view

    view->setInteractive(true);
    view->setFixedSize(window_width,window_height);// View Parameters
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


No_ScrollQGraphicsView::No_ScrollQGraphicsView(QWidget * parent)
: QGraphicsView(parent)
{}

No_ScrollQGraphicsView::No_ScrollQGraphicsView(QGraphicsScene * scene, QWidget * parent)
: QGraphicsView(scene, parent)
{}

void No_ScrollQGraphicsView::wheelEvent(QWheelEvent * event)
{}
