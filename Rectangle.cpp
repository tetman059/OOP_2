#include "Rectangle.h"

#include <exception>
#include <stdexcept>

#define SET_POINT(field)													\
	if (coord.field <= lower_left_point.field) {							\
		upper_right_point.field -= lower_left_point.field - coord.field;	\
		lower_left_point.field = coord.field;								\
	} else if (coord.field >= lower_left_point.field 						\
			&& coord.field <= upper_right_point.field) {					\
		upper_right_point.field += coord.field;								\
		lower_left_point.field += coord.field;								\
	} else if (coord.field >= upper_right_point.field) {					\
		lower_left_point.field += coord.field;								\
		upper_right_point.field += coord.field;								\
	}

void Rectangle::set_lower(const Coordinate& coord) {
	lower_left_point = coord;
}

void Rectangle::set_upper(const Coordinate& coord) {
	upper_right_point = coord;
}

void Rectangle::Print() const {
	std::cout << "(" << lower_left_point.x << ", " << lower_left_point.y <<
			"), (" << upper_right_point.x << ", " << upper_right_point.y << ")" << std::endl;
}

double Rectangle::perimeter() const {
	return 2 * ((upper_right_point.x - lower_left_point.x)
			+ (upper_right_point.y - lower_left_point.y));
}

double Rectangle::area() const {
	return (upper_right_point.x - lower_left_point.x)
			* (upper_right_point.y - lower_left_point.y);
}

void Rectangle::setY(const Coordinate& coord) {
	SET_POINT(y)
}

void Rectangle::setX(const Coordinate& coord) {
	SET_POINT(x)
}

void Rectangle::setSize(const Coordinate& coord1, const Coordinate& coord2) {
	lower_left_point = coord1;
	upper_right_point = coord2;
}

bool Rectangle::comparePerimeter(const Rectangle& lhs, const Rectangle& rhs) const {
	return lhs.perimeter() < rhs.perimeter();
}
bool Rectangle::compareArea(const Rectangle& lhs, const Rectangle& rhs) const {
	return lhs.area() < rhs.area();
}

Rectangle Rectangle::intersection(const Rectangle& lhs, const Rectangle& rhs) const {
	Rectangle rect;
	if (lhs.lower_left_point.x < rhs.lower_left_point.x) {
		rect.lower_left_point = lhs.lower_left_point;
		rect.upper_right_point = rhs.upper_right_point;
	} else if (lhs.lower_left_point.x > rhs.lower_left_point.x &&
			lhs.upper_right_point.x < rhs.upper_right_point.x) {
		rect.lower_left_point = lhs.lower_left_point;
		rect.upper_right_point = rhs.upper_right_point;
	} else if (rhs.lower_left_point.x < lhs.lower_left_point.x) {
		rect.lower_left_point = rhs.lower_left_point;
		rect.upper_right_point = lhs.upper_right_point;
	}
	return rect;
}

Rectangle Rectangle::getMinIntersection(const Rectangle& lhs, const Rectangle& rhs) const {
	Rectangle rect;
	if ((lhs.lower_left_point.x <= rhs.lower_left_point.x) &&
			(lhs.lower_left_point.y <= rhs.lower_left_point.y)) {
		rect.lower_left_point = rhs.lower_left_point;
		rect.upper_right_point = lhs.upper_right_point;
	} else if ((lhs.lower_left_point.x <= rhs.lower_left_point.x) &&
			(lhs.lower_left_point.y >= rhs.lower_left_point.y)) {
		rect.lower_left_point.x = rhs.lower_left_point.x;
		rect.lower_left_point.y = lhs.lower_left_point.y;
		rect.upper_right_point.x = lhs.upper_right_point.x ;
		rect.upper_right_point.y = rhs.upper_right_point.y;
	} else if ((lhs.lower_left_point.x >= rhs.lower_left_point.x) &&
			(lhs.lower_left_point.y >= rhs.lower_left_point.y)) {
		rect.lower_left_point = lhs.lower_left_point;
		rect.upper_right_point = rhs.upper_right_point;
	} else if ((rhs.lower_left_point.x <= lhs.lower_left_point.x) &&
			(rhs.lower_left_point.y >= lhs.lower_left_point.y)) {
		rect.lower_left_point.x = lhs.lower_left_point.x;
		rect.lower_left_point.y = rhs.lower_left_point.y;
		rect.upper_right_point.x = rhs.upper_right_point.x;
		rect.upper_right_point.y = lhs.lower_left_point.y;
	}
	return rect;
}

bool operator < (const Rectangle& lhs, const Rectangle& rhs) {
	return lhs.area() < rhs.area();
}
bool operator > (const Rectangle& lhs, const Rectangle& rhs) {
	return lhs.area() > rhs.area();
}
bool operator == (const Rectangle& lhs, const Rectangle& rhs) {
	return lhs.area() == rhs.area();
}

Rectangle operator "" _rectangle(const char* str, size_t size) {
	Rectangle rect;
	std::string s(str, size);
	double l_x, l_y, u_x, u_y;
	std::istringstream is(s);
	is.ignore(1);
	is >> l_x;
	is.ignore(2);
	is >> l_y;
	is.ignore(4);
	is >> u_x;
	is.ignore(1);
	is >> u_y;
	rect.lower_left_point.x = l_x;
	rect.lower_left_point.y = l_y;
	rect.upper_right_point.x = u_x;
	rect.upper_right_point.y = u_y;
	return rect;
}
