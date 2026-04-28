/*
 * Point.h
 *
 *  Created on: 21.03.2022
 *      Author: herrler
 *  Modified on: 10.04.2025
 *      Author: borrmann
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
private:
	int x_;
	int y_;
public:
	Point(int x=0, int y=0);
	int getX() const;
	int getY() const;
	void setValues(int x, int y);
	void shift(int dx, int dy);
};

#endif /* POINT_H_ */
