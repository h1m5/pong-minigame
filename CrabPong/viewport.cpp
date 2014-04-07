#include "viewport.h"
#include <QKeyEvent>

ViewPort::ViewPort(QWidget *parent, std::string source) :
    QGLWidget(parent)
{
    gameDrawer = new GameDrawer (source);
    isLeftKeyPressed = false;
    isRightKeyPressed = false;
    rotationVar = 0;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start (TIMER_MS);

}

void ViewPort::cleanup ()
{
    delete gameDrawer;
    cleanupGameDrawer ();
}

void ViewPort::initializeGL ()
{
    glEnable (GL_DEPTH_TEST);
    glEnable (GL_COLOR_MATERIAL);
    glEnable (GL_LIGHTING);
    glEnable (GL_NORMALIZE);
    glEnable (GL_CULL_FACE);
    glShadeModel (GL_SMOOTH);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    gameDrawer->initGameDrawer ();
}

void ViewPort::resizeGL (int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    gluPerspective(45.0, (double)w / (double)h, 0.02, 5.0);
    glFrustum(-0.5,0.5,-0.5,0.5,1,10);
}

void ViewPort::paintGL ()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.5f, -0.3f, -1.8f);
    glRotatef(50, 1, 0, 0);
    glRotatef(180, 0, 1, 0);

    //This makes the camera rotate slowly over time
    glTranslatef(0.5f, 0, 0.5f);
    glRotatef(3 * sin(rotationVar), 0, 1, 0);
    glTranslatef(-0.5f, 0, -0.5f);

    gameDrawer->draw();

//    glutSwapBuffers ();
}

void ViewPort::mousePressEvent (QMouseEvent *event)
{
    if (event->button () == Qt::LeftButton){
        std::cout << "You pressed the left mouse button"<<std::endl;
        if (gameDrawer->isGameOver ()){
            gameDrawer->startNewGame (2.2f, 20);
        }
    }
}

void ViewPort::update ()
{
    gameDrawer->advance((float)TIMER_MS / 1000);

    rotationVar += 0.2f * (float)TIMER_MS / 1000;
    while (rotationVar > 2 * PI) {
        rotationVar -= 2 * PI;
    }
    updateGL ();
}
