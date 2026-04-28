/*
 * Rectangle.h
 *
 *  Created on: 04.04.2022
 *      Author: herrler
 *  Modified on: 10.04.2025
 *      Author: borrmann
 */
#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "point.h"
#include <QColor>

class Rectangle {
private:
	Point center_;
	int length_;
	int width_;
  QColor color_ = Qt::black;
public:
	Rectangle(int length, int width, int xcenter, int ycenter);
	Rectangle(int length, int width, Point center);
	Rectangle(Point lowerLeft, Point upperRight);
	Rectangle();

	void print() const;
	int getMaxX() const;
	int getMinX() const;
	int getMaxY() const;
	int getMinY() const;
  QColor getColor() const;
  void setColor(const QColor& color); 
  void move(int dx, int dy);
};

Rectangle intersectRectangles(Rectangle rect1, Rectangle rect2);

#endif /* RECTANGLE_H_ */
