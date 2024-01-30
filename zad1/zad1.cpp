#include <iostream>
#include <cmath> //sqrt
#include <stdlib.h> //abs
#include <string>

class point2d
{
	double x;
	double y;

public:
	point2d(double x, double y) : x(x), y(y) {}
	double valueX() const { return x; }
	double valueY() const { return y; }
};

double hypot(point2d p1, point2d p2)
{
	double udaljenost;
	udaljenost = sqrt(abs(p1.valueX() - p2.valueX()) + (p1.valueY() - p2.valueY()));
	if (udaljenost < 1e-4) throw hypot_err("Udaljenost je premala!");
	return udaljenost;
}

class hypot_err : std::exception
{
public:
	std::string s;
	hypot_err(const char* s) : std::exception(s) {}
};

int main()
{
	try
	{
		int x1, x2, y1, y2;
		std::cout << "Upisi koordinate prve tocke :";
		std::cin >> x1, y1;
		std::cout << "Upisi koordinate druge tocke :";
		std::cin >> x2, y2;

		point2d t1(x1, y1);
		point2d t2(x2, y2);
		double udaljenost;
		udaljenost = hypot(t1, t2);
		std::cout << "Udaljenost izmedu tocaka: " << std::fixed << std::setprecision(2) << udaljenost << std::endl;

	}
	catch (const hypot_err& err)
	{
		std::cout << err.s << std::endl;
	}
}