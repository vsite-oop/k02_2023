#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <format>
#include <numeric>
using namespace std;

struct student {
	string name, surname;
	std::array<int, 4> scores;
	int total() const {
		return accumulate(begin(scores), end(scores), 0);
	}
	int grade() const {
		const auto t = total();
		return t < 20 ? 1 : 2 + (t - 19) / 8;
	}
};

istream& operator>>(istream& is, student& s) {
	if(is >> s.name >> s.surname)
		copy_n(istream_iterator<int>(is), s.scores.size(), s.scores.begin());
	return is;
}

ostream& operator<<(ostream& os, const student& s) {
	return os << format("{}. {} {} ({})", s.name.front(), s.surname, s.total(), s.grade());
}

int main(int argc, char* argv[]) {
	ifstream f(argv[1]);
	vector<student> v;
	copy(istream_iterator<student>(f), {}, back_inserter(v));
	v.erase(remove_if(begin(v), end(v), [](const student& s) {
		return any_of(begin(s.scores), end(s.scores), [](int score) { return score < 0; });
		}), end(v));
	sort(begin(v), end(v), [](const student& a, const student& b) {
		return a.total() != b.total() ? a.total() > b.total() : a.surname < b.surname;
		});
	copy(begin(v), end(v), ostream_iterator<student>(cout, "\n"));
}
