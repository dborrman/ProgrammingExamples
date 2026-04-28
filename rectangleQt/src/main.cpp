#include <QApplication>
#include <vector>
#include <iostream>

#include "window.h"
#include "canvas.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    return app.exec();
}
