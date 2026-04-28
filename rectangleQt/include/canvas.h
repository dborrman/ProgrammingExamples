#ifndef _CANVAS_H_
#define _CANVAS_H_

#include <QApplication>
#include <QMouseEvent>
#include <QPainter>
#include <QWidget>
#include <vector>
#include <iostream>

#include "rectangle.h"

class Canvas : public QWidget {
  public:
    Canvas(QWidget *parent = nullptr);

  protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

  private:
    std::vector<Rectangle> rectangles;
    int counter;
};

#endif
