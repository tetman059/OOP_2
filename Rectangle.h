#pragma once

#include <iostream>
#include <iomanip>
#include <cstdint>

struct Coordinate { // ���������� ������� �����
	double x, y;
};

class Rectangle {
public:
	void Print() const; // ������
	void set_lower(const Coordinate& coord); // ������ ����������
	void set_upper(const Coordinate& coord);
	double perimeter() const; // ��������
	double area() const; // �������
	void setY(const Coordinate& coord); // ����������� ����� ��� ��
	void setX(const Coordinate& coord); // ����������� ����� ��� ��
	void setSize(const Coordinate& coord1, const Coordinate& coord2); // �������� ������ ��������������
	bool comparePerimeter(const Rectangle& lhs, const Rectangle& rhs) const; // ��������� �� ���������
	bool compareArea(const Rectangle& lhs, const Rectangle& rhs) const; // ��������� �� �������
	Rectangle intersection(const Rectangle& lhs, const Rectangle& rhs) const; // ����������� ���������������
	Rectangle getMinIntersection(const Rectangle& lhs, const Rectangle& rhs) const; // ���������� �� �����������
	friend Rectangle operator "" _rectangle(const char* str, size_t size); // ���������������� �������
private:
	Coordinate lower_left_point, upper_right_point;
};

bool operator < (const Rectangle& lhs, const Rectangle& rhs);
bool operator > (const Rectangle& lhs, const Rectangle& rhs);
bool operator == (const Rectangle& lhs, const Rectangle& rhs);
