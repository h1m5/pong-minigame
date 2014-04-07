#ifndef MYFRAME_H
#define MYFRAME_H

#include <QDialog>
#include <QtWidgets>
#include "viewport.h"

class MyFrame : public QDialog
{
    Q_OBJECT

public:
    MyFrame(QWidget *parent = 0, std::string source = "");
    ~MyFrame();

public slots:

protected:
    void keyPressEvent (QKeyEvent *);
    void keyReleaseEvent (QKeyEvent *);

private:
    ViewPort *myScene;
    QVBoxLayout *vLayout;
    bool isLeftKeyPressed;
    bool isRightKeyPressed;
};

#endif // MYFRAME_H
