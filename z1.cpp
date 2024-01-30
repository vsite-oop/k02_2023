#include <iostream>
#include <format>
using namespace std;

struct hypot_err : public std::exception {
	explicit hypot_err(const char* txt) : std::exception(txt) {}
};

template <typename T>
class point2d {
	T x, y;
	friend std::istream& operator>>(std::istream& is, point2d& p) {
		return is >> p.x >> p.y;
	}
	friend double hypot(const point2d& a, const point2d& b);
};

double hypot(const point2d<int>& a, const point2d<int>& b) {
	static constexpr auto min_dist = 1e-4;
	const auto dx = a.x - b.x;
	const auto dy = a.y - b.y;
	const auto d = sqrt(dx * dx + dy * dy);
	if (d < min_dist)
		throw hypot_err("too small");
	return d;
}

int main() {
	try {
		point2d<int> a, b; cin >> a >> b;
		cout << format("{:.2f}", hypot(a, b));
	}
	catch (const std::exception& x) {
		cout << x.what() << '\n';
	}
}
