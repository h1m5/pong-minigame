#include "myframe.h"

MyFrame::MyFrame(QWidget *parent, std::string source)
    : QDialog(parent)
{
    setSizePolicy (QSizePolicy::Expanding, QSizePolicy::Expanding);
    myScene = new ViewPort(0, source);
    myScene->setMinimumSize (500,500);

    vLayout = new QVBoxLayout();
    vLayout->addWidget (myScene);

    setLayout (vLayout);
}


MyFrame::~MyFrame()
{

}

void MyFrame::keyPressEvent (QKeyEvent *event)
{
    switch (event->key ()) {
    case Qt::Key_Space:
        std::cout << "You pressed Space"<< std::endl;
        if (myScene->gameDrawer->isGameOver ()){
            myScene->gameDrawer->startNewGame (2.2f, 20);
        }
        break;

    case Qt::Key_Escape:
        std::cout << "You pressed Escape" << std::endl;
        exit(0);
        break;

    case Qt::Key_Left:
        isLeftKeyPressed = true;
        if (isRightKeyPressed) {
            myScene->gameDrawer->setPlayerCrabDir(0);
        }
        else {
            myScene->gameDrawer->setPlayerCrabDir(1);
        }
        break;

    case Qt::Key_Right:
        isRightKeyPressed = true;
        if (isLeftKeyPressed) {
            myScene->gameDrawer->setPlayerCrabDir(0);
        }
        else {
            myScene->gameDrawer->setPlayerCrabDir(-1);
        }
        break;

    default:
        break;
    }
}

void MyFrame::keyReleaseEvent (QKeyEvent *event)
{
    switch (event->key ()) {
    case Qt::Key_Left:
        isLeftKeyPressed = false;
        if (isRightKeyPressed) {
            myScene->gameDrawer->setPlayerCrabDir(-1);
        }
        else {
            myScene->gameDrawer->setPlayerCrabDir(0);
        }
        break;

    case Qt::Key_Right:
        isRightKeyPressed = false;
        if (isLeftKeyPressed) {
            myScene->gameDrawer->setPlayerCrabDir(1);
        }
        else {
            myScene->gameDrawer->setPlayerCrabDir(0);
        }
        break;

    default:
        break;
    }
}

