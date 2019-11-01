/*Разработать класс Rectangle, представляющий собой прямоугольник со сторонами, параллельными осям координат.
 * Поля – координаты левого нижнего и правого верхнего угла. Требуется реализовать следующие методы:
 * вычисление площади и периметра, перемещения вдоль осей, изменение размеров, сравнение по площади и по периметру.
 * Реализовать метод получения прямоугольника, представляющего общую часть (пересечение) двух прямоугольников.
 * Реализовать метод объединения двух прямоугольников: наименьший прямоугольник, включающего оба заданных прямоугольника.
Необходимо реализовать:
-	операцию приведения к типу double, вычисляющую площадь прямоугольника;
-	операцию префиксного и постфиксного инкремента, увеличивающую одновременно размеры сторон прямоугольника.
-	операции сравнения (больше, меньше, равно);
Необходимо реализовать пользовательский литерал для работы с константами типа Rectangle.*/

#include "Rectangle.h"

#include <iostream>

using namespace std;

int main() {
	Rectangle rect;
	int option = 11;
	bool flag = true;
	while (flag) {
		switch (option) {
		case 0:
			flag = false;
			break;
		case 1: {
			Coordinate lower, upper;
			cout << "Input the coordinates of rectangle" << endl;
			cin >> lower.x >> lower.y >> upper.x >> upper.y;
			rect.set_lower(lower);
			rect.set_upper(upper);
			rect.Print();
			break;
		}
		case 2:
			cout << "Perimeter of rectangle: " << rect.perimeter() << endl;
			break;
		case 3:
			cout << "Area of rectangle: " << rect.area() << endl;
			break;
		case 4: {
			cout << "Input the coordinates: ";
			Coordinate y;
			cin >> y.y;
			rect.setY(y);
			rect.Print();
			break;
		}
		case 5: {
			cout << "Input the coordinates: ";
			Coordinate x;
			cin >> x.x;
			rect.setX(x);
			rect.Print();
			break;
		}
		case 6: {
			cout << "Input lower and upper coordinates: ";
			Coordinate lower, upper;
			cin >> lower.x >> lower.y >> upper.x >> upper.y;
			rect.setSize(lower, upper);
			rect.Print();
			break;
		}
		case 7: {
			Rectangle tmp;
			Coordinate lower, upper;
			cout << "Input the values of second rectangle: ";
			cin >> lower.x >> lower.y >> upper.x >> upper.y;
			tmp.set_lower(lower);
			tmp.set_upper(upper);
			if (rect.comparePerimeter(rect, tmp) == true) {
				cout << "Second rect perimeter is bigger" << endl;
			} else {
				cout << "First rect perimeter is bigger" << endl;
			}
			break;
		}
		case 8: {
			Rectangle tmp;
			Coordinate lower, upper;
			cout << "Input the values of second rectangle: ";
			cin >> lower.x >> lower.y >> upper.x >> upper.y;
			tmp.set_lower(lower);
			tmp.set_upper(upper);
			if (rect.compareArea(rect, tmp) == true) {
				cout << "Second rect area is bigger" << endl;
			} else {
				cout << "First rect area is bigger" << endl;
			}
			break;
		}
		case 9: {
			Rectangle tmp;
			Coordinate lower, upper;
			cout << "Input the values of second rectangle: ";
			cin >> lower.x >> lower.y >> upper.x >> upper.y;
			tmp.set_lower(lower);
			tmp.set_upper(upper);
			rect = rect.intersection(rect, tmp);
			rect.Print();
			break;
		}
		case 10: {
			Rectangle tmp;
			Coordinate lower, upper;
			cout << "Input the values of second rectangle: ";
			cin >> lower.x >> lower.y >> upper.x >> upper.y;
			tmp.set_lower(lower);
			tmp.set_upper(upper);
			rect = rect.getMinIntersection(rect, tmp);
			rect.Print();
			break;
		}
		case 11:
			cout << "MENU :" << endl <<
			"0. Exit program" << endl <<
			"1. Create rectangle" << endl <<
			"2. Perimeter" << endl <<
			"3. Area" << endl <<
			"4. Move rectangle by y" << endl <<
			"5. Move rectangle by x" << endl <<
			"6. Resize rectangle" << endl <<
			"7. Compare by perimeter" << endl <<
			"8. Compare by area" << endl <<
			"9. Get intersection of rectangles" << endl <<
			"10. Get minimal rectangle with intersection" << endl <<
			"11. Print menu" << endl;
			break;
		}
		if (flag) {
			cout << "Enter the number of action: ";
			cin >> option;
		}
	}
	return 0;
}
