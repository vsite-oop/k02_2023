//#include <iomanip>
//#include <iostream>
//#include <format>
//
//
//template <typename T>
//class point2d {
//	T x;
//	T y;
//public:
//	point2d() : x(T()), y(T()) {}
//	point2d(T x_value, T y_value) : x(x_value), y(y_value) {};
//	T get_x() const { return x; };
//	T get_y() const { return y; };
//	friend std::istream& operator>>(std::istream& is, point2d& point) {
//		is >> point.x >> point.y;
//		return is;
//	}
//};
//
//class hypot_err : public std::exception {
//public:
//	hypot_err(const char* msg) : std::exception(msg) {}
//};
//
//const double min_dist = 1e-4;
//
//template<typename T>
//double hypot(const point2d<T>& p1, const point2d<T>& p2) {
//	double dx = p1.get_x() - p2.get_x();
//	double dy = p1.get_y() - p2.get_y();
//	double distance = std::sqrt(pow(dx, 2) + pow(dy, 2));
//
//	if (distance < min_dist)
//		throw hypot_err("Udaljenost manja od 10^-4.");
//
//	return distance;
//}
//
//int main1() {
//	try {
//		std::cout << "Koordinate tocke 1: ";
//		point2d<int> p1;
//		std::cin >> p1;
//
//		std::cout << "Koordinate tocke 2: ";
//		point2d<int> p2;
//		std::cin >> p2;
//		std::cout << std::endl;
//
//		double distance = hypot(p1, p2);
//		std::cout << std::format("Udaljenost: {:.2f}", distance) << std::endl;
//
//	}
//	catch (const hypot_err& err) {
//		std::cerr << err.what() << std::endl;
//	}
//}