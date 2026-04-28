#ifndef _MY_WINDOW_H_
#define _MY_WINDOW_H_

#include <QMainWindow>
#include <QWidget>

#include "canvas.h"

class MainWindow : public QMainWindow {
public:
    MainWindow();
    ~MainWindow();
    Canvas* getCanvas();

private:
    Canvas *canvas;
};

#endif
