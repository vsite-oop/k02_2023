#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <format>
#include <array>
#include <numeric>


struct student {
    std::string ime;
    std::string prezime;
    std::array<int, 4> bodovi;
    int sum;
    int ocjena;
};

std::istream& operator>>(std::istream& is, student& student) {
    return is >> student.ime >> student.prezime >> student.bodovi[0] >> student.bodovi[1] >> student.bodovi[2] >> student.bodovi[3];
}

int main(const int argc, const char* argv[]) {
    std::ifstream file(argv[1]);
    std::istream_iterator <student> file_start(file), file_end;


    std::vector<student> students;
    std::copy_if(file_start, file_end, std::back_inserter(students), [](const student& s) {
        if (s.bodovi[0] >= 0 && s.bodovi[1] >= 0 && s.bodovi[2] >= 0 && s.bodovi[3] >= 0) {
            return true;
        }
        return false;
    });

    for (auto& s : students) {
        s.sum = std::accumulate(s.bodovi.begin(), s.bodovi.end(), 0);

        if (s.sum >= 43)
            s.ocjena = 5;
        else if (s.sum >= 35)
            s.ocjena = 4;
        else if (s.sum >= 27)
            s.ocjena = 3;
        else if (s.sum >= 20)
            s.ocjena = 2;
        else
            s.ocjena = 1;
    }

    std::sort(students.begin(), students.end(), [](const student& s1, const student& s2) {
        if (s1.sum == s2.sum)
            return s1.prezime < s2.prezime;
        else
            return s1.sum > s2.sum;
    });

    for (const auto& s : students) {
        std::cout << std::format("{}. {} {} ({}) \n", s.ime[0], s.prezime, s.sum, s.ocjena);
    }

}

