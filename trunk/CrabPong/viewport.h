#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QtOpenGL>
//#include <QWheelEvent>
//#include <QKeyEvent>
//#include <QMouseEvent>
//#include <OpenGL.h>
//#include <gl/GLU.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <qopengl.h>
#include "gamedrawer.h"
#include <QTimer>
#define PI 3.1415926535f
#define TIMER_MS 25

class ViewPort : public QGLWidget
{
    Q_OBJECT
public:
    explicit ViewPort(QWidget *parent = 0, std::string source = "");
    void cleanup ();
    GameDrawer *gameDrawer;
signals:

public slots:
    void update ();

protected:
    void initializeGL ();
    void resizeGL (int, int);
    void paintGL ();
    void mousePressEvent (QMouseEvent *);


private:

    bool isLeftKeyPressed;
    bool isRightKeyPressed;
    float rotationVar;

};

#endif // VIEWPORT_H
