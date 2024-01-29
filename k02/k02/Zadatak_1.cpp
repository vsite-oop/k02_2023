#include <exception>
#include <iostream>
#include <format>

class hypot_err : public std::exception {
public:
    hypot_err(const char* msg) : std::exception(msg) {}
};

template <typename T>
class Point2d {
    T x;
    T y;

public:
    double hypot(T x, T y) const {
        double dist = sqrt(x * x + y * y);

        if (dist < 10e-4) {
            throw hypot_err("Udaljenost je manja od 10e-4");
        }
       
        return sqrt(x * x + y * y);
    }
};

int main() {
    Point2d<int> p;
    try {
        double dist = p.hypot(0, 0);

        std::cout << std::format("Udaljenost: {:.2f}", dist);
    }
    catch (hypot_err& e) {
        std::cout << std::format("Greska: {}", e.what());
    }
    return 0;
}