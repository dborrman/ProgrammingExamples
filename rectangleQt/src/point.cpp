/*
 * Point.cpp
 *
 *  Created on: 21.03.2022
 *      Author: herrler
 *  Modified on: 10.04.2025
 *      Author: borrmann
 */

#include "point.h"

Point::Point(int x, int y) : x_(x), y_(y) {
	// do nothing
}

int Point::getX() const {
	return x_;
}

int Point::getY() const {
	return y_;
}

void Point::setValues(int x, int y) {
	x_ = x;
	y_ = y;
}

void Point::shift(int dx, int dy) {
	x_ = x_ + dx;
	y_ = y_ + dy;
}

