//Napišite template klasu point2d (ima privatne članove za x i y).
//Napišite funkciju hypot koja prima dvije točke i vraća udaljenost između točaka.
//U slučaju da je udaljenost manja od 10 - 4 (koristite const varijablu), funkcija
//baca iznimku hypot_err(izvedite je iz std::exception, prima tekst greške u konstruktoru).
//U programu unesite dvije točke(sa cjelobrojnim koordinatama) i 
//ispišite njihovu udaljenost(zaokruženu na dvije decimale).U slučaju greške ispišite poruku greške.
#include <iomanip>
#include <iostream>
#include <format>

using namespace std::string_literals;
const double min_dist = 1e-4;

template <typename T>
class point2d {
	T x;
	T y;
public:
	point2d() : x(T()), y(T()) {}
	point2d(T x_value, T y_value) : x(x_value), y(y_value){};
	T get_x() const { return x; };
	T get_y() const { return y; };
	friend std::istream& operator>>(std::istream& is, point2d& point) {
		is >> point.x >> point.y;
		return is;
	}
};

class hypot_err : public std::exception {
public:
	hypot_err(const char* msg) : std::exception(msg) {}
};

template<typename T>
double hypot(const point2d<T>& p1, const point2d<T>& p2) {
	double dx = p1.get_x() - p2.get_x();
	double dy = p1.get_y() - p2.get_y();
	double distance = std::sqrt(pow(dx,2) + pow(dy,2));

	if (distance < min_dist)
		throw hypot_err("Distance is too small!");

	return distance;
}

int main() {
	try {
		std::cout << "First point coordinates: ";
		point2d<int> p1;
		std::cin >> p1;
		std::cout << "Second point coordinates: ";
		point2d<int> p2;
		std::cin >> p2;
		std::cout << std::endl;

		double distance = hypot(p1, p2);
		std::cout << std::format("Distance between points: {:.2f}", distance) << std::endl;

	}
	catch (const hypot_err& err) {
		std::cerr << err.what() << std::endl;
	}
}