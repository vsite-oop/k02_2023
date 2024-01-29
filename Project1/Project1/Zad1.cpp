#include <iostream>
#include <cmath>
#include <exception>
#include <iomanip>


template<typename T>
class Point2D {
	T x;
	T y;
public:
	Point2D(T x_value, T y_value) : x(x_value), y(y_value) {}

	T getX() const { return x; }
	T getY() const { return y; }
};

class hypot_err : public std::exception {
	std::string poruka;
public:
	hypot_err(const std::string& por) :poruka(por) {}
	const char* what() const noexcept override {
		return poruka.c_str();
	}
};

template<typename T>
double hypot(const Point2D<T>& p1, const Point2D<T>& p2) {
	double dx = p1.getX() - p2.getX();
	double dy = p1.getY() - p2.getY();
	double distance = std::sqrt(dx * dx + dy * dy);

	const double min_dist = 1e-4;

	if (distance < min_dist) {
		throw hypot_err("Udaljenost manja od 10^-4");
	}
	return distance;
};

int main() {
	try {
		double x1, y1, x2, y2;
		std::cout << "Unesite koordinate prve tocke (x y): ";
		std::cin >> x1 >> y1;
		std::cout << "Unesite koordinate druge tocke (x y): ";
		std::cin >> x2 >> y2;

		Point2D<double> p1(x1, y1);
		Point2D<double> p2(x2, y2);

		double distance = hypot(p1, p2);
		std::cout << std::fixed << std::setprecision(2);
		std::cout <<"Udaljenost: "<< distance << std::endl;
	}
	catch (const hypot_err& e) {
		std::cout <<"Greška:"<< e.what() << std::endl;
	}
}