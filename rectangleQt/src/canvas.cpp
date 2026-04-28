#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
  counter = 0;
}

void Canvas::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  
  for (const Rectangle &rect : rectangles) {
    QPen pen(rect.getColor(), 5);
    painter.setPen(pen);
    QPoint p1(rect.getMinX(),rect.getMinY());
    QPoint p2(rect.getMaxX(),rect.getMaxY());
    QRect r1(p1,p2);
    painter.drawRect(r1);
    painter.drawPoint(p1);
    painter.drawPoint(p2);
  }
}

void Canvas::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    switch(counter) {
      case 0: {
              Rectangle r1(200,100,200,200);
              rectangles.push_back(r1);
              }
              break;
      case 1: {
              rectangles[0].setColor(Qt::red); 
              } 
              break;
      case 2: {
              Rectangle r2(300,50,200,200);
              r2.setColor(Qt::yellow);
              rectangles.push_back(r2);
              } 
              break;
      case 3: {
              Rectangle r3 = intersectRectangles(rectangles[0],rectangles[1]);
              r3.setColor(Qt::magenta);
              rectangles.push_back(r3);
              }
              break;
      case 4: {
              Rectangle r11(200,100,500,200);
              r11.setColor(Qt::blue);
              rectangles.push_back(r11);
              }
              break;
      case 5: {
              Rectangle r12(300,100,400,400);
              r12.setColor(Qt::green);
              rectangles.push_back(r12);
              }
              break;
      case 6: {
              Rectangle r13 = intersectRectangles(rectangles[3],rectangles[4]);
              r13.setColor(Qt::cyan);
              rectangles.push_back(r13);
              }
              break;
      case 7: rectangles[4].move(-5,-50);
              rectangles[5] = intersectRectangles(rectangles[3],rectangles[4]);
              rectangles[5].setColor(Qt::darkCyan);
              break;
      case 8: rectangles[4].move(-5,-50);
              rectangles[5] = intersectRectangles(rectangles[3],rectangles[4]);
              rectangles[5].setColor(Qt::cyan);
              break;
      case 9: rectangles[4].move(-5,-50);
              rectangles[5] = intersectRectangles(rectangles[3],rectangles[4]);
              rectangles[5].setColor(Qt::darkCyan);
              break;
      default: rectangles.clear();
              counter = -1;
    }
    counter++;
    update();
  }
}

