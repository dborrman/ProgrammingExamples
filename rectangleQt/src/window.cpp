#include "window.h"
    
MainWindow::MainWindow() {
  setWindowTitle("Simple Drawing Canvas");
  canvas = new Canvas(this);
  setCentralWidget(canvas);
  resize(800, 600);
}
    
MainWindow::~MainWindow() {
  delete canvas;
}

