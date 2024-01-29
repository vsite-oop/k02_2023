
#include <iostream>
#include <cmath>
#include <string>

class hypot_err : public std::exception {
    std::string msg;
};

template <typename T>
class point2d {
    T x, y;

public:
    point2d() : x(0), y(0) {}
    point2d(T x, T y) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }

    void setX(T newX) { x = newX; }
    void setY(T newY) { y = newY; }

};

template <typename T>
double hypot(const point2d<T>& p1, const point2d<T>& p2) {
    double dx = p1.getX() - p2.getX();
    double dy = p1.getY() - p2.getY();
    double d = sqrt(dx * dx + dy * dy);
    if (d < 10e-4)
        throw hypot_err("Premala udaljenost");
    return d;
}

int main() {
    point2d<int> p1{}, p2{};

    int x1, y1, x2, y2;

    std::cout << "Unesite koordinate prve tocke: ";
    std::cin >> x1 >> y1;
    p1.setX(x1);
    p1.setY(y1);

    std::cout << "Unesite koordinate druge tocke: ";
    std::cin >> x2 >> y2;
    p2.setX(x2);
    p2.setY(y2);

    try {
        std::cout << "Udaljenost izmedju tocaka je " << hypot(p1, p2) << std::endl;
    }
    catch (const hypot_err& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
