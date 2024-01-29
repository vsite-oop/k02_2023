#include<iostream>

class point2D {
	double x, y;
public:
	point2D() {};
	point2D(double a, double b) { x = a; y = b; }
	friend double hypot(const point2D& a, const point2D& b);
	friend std::istream& operator>>(std::istream& is, point2D& a);
};
class hypot_err : std::exception {};

double hypot(const point2D& a, const point2D& b) {
	double d =sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
	if (d < pow(10, -4)) throw hypot_err();
	return d;
}

std::istream& operator>>(std::istream& is, point2D& a) {
	return is >> a.x >> a.x;
}




int main() {
	try
	{
		point2D a;
		std::cin >> a;
		point2D b;
		std::cin >> b;
		std::cout << hypot(a, b) << "\n";
	}
	catch (hypot_err) {
		std::cout << "less than 10^(-4)";
	}
}