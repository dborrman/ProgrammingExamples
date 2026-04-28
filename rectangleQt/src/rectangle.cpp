/*
 * Rectangle.cpp
 *
 *  Created on: 04.04.2022
 *      Author: herrler
 *  Modified on: 10.04.2025
 *      Author: borrmann
 */

#include "rectangle.h"
#include <iostream>
#include <algorithm>    // std::max
using namespace std;

Rectangle::Rectangle(int length, int width, int xcenter, int ycenter) :
		center_(xcenter, ycenter) {
	length_ = length;
	width_ = width;
}

Rectangle::Rectangle(int length, int width, Point center) :
		center_(center) {
	length_ = length;
	width_ = width;
}

Rectangle::Rectangle(Point lowerLeft, Point upperRight) :
		center_(upperRight.getX() + lowerLeft.getX() / 2,
				upperRight.getY() + lowerLeft.getY() / 2) {
	length_ = upperRight.getX() - lowerLeft.getX();
	width_ = upperRight.getY() - lowerLeft.getY();
}

Rectangle::Rectangle() :
		length_(0), width_(0), center_(0, 0) {

}

void Rectangle::print() const {
	cout << "Rectangle(length=" << length_ << ",width=" << width_ << " center=("
			<< center_.getX() << "," << center_.getY() << ")" << endl;
	cout << "x=(" << getMinX() << "," << getMaxX() << ")" << endl;
	cout << "y=(" << getMinY() << "," << getMaxY() << ")" << endl;
}

void Rectangle::setColor(const QColor& color) {
  color_ = color;
}

QColor Rectangle::getColor() const {
  return color_;
}

void Rectangle::move(int dx, int dy) {
  center_.shift(dx,dy); 
}

int Rectangle::getMaxX() const {
	return center_.getX() + (length_ / 2);
}

int Rectangle::getMinX() const {
	return center_.getX() - (length_ / 2);
}

int Rectangle::getMaxY() const {
	return center_.getY() + (width_ / 2);
}

int Rectangle::getMinY() const {
	return center_.getY() - (width_ / 2);
}

Rectangle intersectRectangles(Rectangle rect1, Rectangle rect2) {
	// find all the cases with no intersection
	if (rect1.getMaxX() < rect2.getMinX())
		return Rectangle();
	if (rect2.getMaxX() < rect1.getMinX())
		return Rectangle();
	if (rect1.getMaxY() < rect2.getMinY())
		return Rectangle();
	if (rect2.getMaxY() < rect1.getMinY())
		return Rectangle();
	// now we have a intersection for sure
	int left = max(rect1.getMinX(), rect2.getMinX());
	int right = min(rect1.getMaxX(), rect2.getMaxX());
	int down = max(rect1.getMinY(), rect2.getMinY());
	int up = min(rect1.getMaxY(), rect2.getMaxY());
	int length = right - left;
	int width = up - down;
//	if (width == 0)
//		length = 0;
//	if (length == 0)
//		width = 0;
	return Rectangle(length, width, (left + right) / 2, (up + down) / 2);
}

