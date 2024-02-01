#include <iostream>
#include <cmath>
#include <format>
using namespace std;


class hypot_err : public exception {
	string s1;
public:
	hypot_err(string s) : s1(s) {};
	const char* what() const noexcept override {
		return s1.c_str();
	}
};
template<typename T>
class point2d {
	T x, y;
public:
	point2d(T v1 = 0, T v2 = 0) : x(v1), y(v2) {};
	friend istream& operator >>(istream& is,point2d& p)
	{
		return is >> p.x >> p.y;
	}
	T getX()
	{
		return x;
	}
	T getY()
	{
		return y;
	}
};
template<typename T>
double hypot(point2d<T> p1,point2d<T> p2)
{
	T x = p2.getX() - p1.getX();
	T y = p2.getY() - p1.getY();
	const double d = 1e-4;
	double udaljenost = sqrt(x*x+y*y);
	if (udaljenost < d)
		throw hypot_err("Udaljenost ne smije biti manja od 10^-4");
	else
		return udaljenost;
}

int main()
{
	point2d<int> p1, p2;
	try {
		cin >> p1 >> p2;
		cout << format("{:.2f}",hypot(p1, p2));
	}
	catch (const exception& i)
	{
		cout << i.what();
	}



	return 0;
}