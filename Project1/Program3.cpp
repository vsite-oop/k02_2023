#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;
struct student {
	string ime,prezime;
	array<int, 4> bodovi;
public:
	int suma() const {
		return accumulate(begin(bodovi), end(bodovi), 0);
	}
};
istream& operator >>(istream& is, student& s)
{
	return is >> s.ime >> s.prezime >> s.bodovi[0] >> s.bodovi[1] >> s.bodovi[2] >> s.bodovi[3];
}
bool izbaci(student& s)
{
	if (s.bodovi[0] < 0 || s.bodovi[1] < 0 || s.bodovi[2] < 0)
		return true;
	else
		return false;
}
bool operator <(student& s1, student& s2)
{
	if (s1.suma() == s2.suma())
		return s1.prezime < s2.prezime;
	else
		return s1.suma() > s2.suma();
}
ostream& operator <<(ostream& os, const student& s)
{
	int ocjena;
	int b = s.suma();
	if (b >= 43 && b <= 50)
		ocjena = 5;
	else if (b >= 35 && b <= 42)
		ocjena = 4;
	if (b >= 27 && b <= 34)
		ocjena = 3;
	if (b >= 20 && b <= 26)
		ocjena = 2;
	if (b >= 0 && b <= 19)
		ocjena = 1;
	return os << s.ime[0] << ". " << s.prezime << " " << b << " " << "(" << ocjena << ")";
}

int main(int argc, const char* argv[]) {
	ifstream f(argv[1]);
	//ifstream f("oop.txt");
	vector<student> v;
	istream_iterator<student> in(f), ends;
	copy(in, ends, back_inserter(v));
	v.erase(remove_if(begin(v), end(v), izbaci), end(v));
	sort(begin(v), end(v));
	ostream_iterator<student> os(cout, "\n");
	copy(begin(v), end(v), os);




	return 0;
}