#pragma once

#include <iostream>
#include <iomanip>
#include <cstdint>

struct Coordinate { // координаты угловых точек
	double x, y;
};

class Rectangle {
public:
	void Print() const; // печать
	void set_lower(const Coordinate& coord); // задаем координаты
	void set_upper(const Coordinate& coord);
	double perimeter() const; // периметр
	double area() const; // площадь
	void setY(const Coordinate& coord); // перемещение вдоль оси оУ
	void setX(const Coordinate& coord); // перемещение вдоль оси оХ
	void setSize(const Coordinate& coord1, const Coordinate& coord2); // изменить размер прямоугольника
	bool comparePerimeter(const Rectangle& lhs, const Rectangle& rhs) const; // сравнение по периметру
	bool compareArea(const Rectangle& lhs, const Rectangle& rhs) const; // сравнение по площади
	Rectangle intersection(const Rectangle& lhs, const Rectangle& rhs) const; // пересечение прямоугольников
	Rectangle getMinIntersection(const Rectangle& lhs, const Rectangle& rhs) const; // наименьший из объединения
	friend Rectangle operator "" _rectangle(const char* str, size_t size); // пользовательский литерал
private:
	Coordinate lower_left_point, upper_right_point;
};

bool operator < (const Rectangle& lhs, const Rectangle& rhs);
bool operator > (const Rectangle& lhs, const Rectangle& rhs);
bool operator == (const Rectangle& lhs, const Rectangle& rhs);
