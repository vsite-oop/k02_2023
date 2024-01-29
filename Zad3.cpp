#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <iterator>
#include <format>


struct Student {
    std::string name;
    std::string lName;
    std::array<int, 4> bodovi;
    int sumB;
};

int calculate_grade(int bodovi) {
    if (bodovi >= 43) return 5;
    else if (bodovi >= 35) return 4;
    else if (bodovi >= 27) return 3;
    else if (bodovi >= 20) return 2;
    else return 1;
}

std::istream& operator>>(std::istream& stream, Student& s) {
    stream >> s.name >> s.lName;
    for (int i = 0; i < 4; ++i) {
        stream >> s.bodovi[i];
    }
    s.sumB = std::accumulate(s.bodovi.begin(), s.bodovi.end(), 0);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Student& s) {
    stream << std::format("{}. {} {} ({})", s.name[0], s.lName, s.sumB, calculate_grade(s.sumB));
    return stream;
}

int main(const int argc, const char* argv[]) {
    std::vector<Student> students;
    std::ifstream file(argv[1]);
    std::istream_iterator<Student> file_start(file), file_end;
    std::copy_if(file_start, file_end, std::back_inserter(students), [](const Student& s) {
        return std::all_of(s.bodovi.begin(), s.bodovi.end(), [](int bod) { return bod >= 0; });
        });

    std::sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return (s1.sumB > s2.sumB);
        });

    std::copy(students.begin(), students.end(), std::ostream_iterator<Student>(std::cout, "\n"));

    return 0;
}