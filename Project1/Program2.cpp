#include <iostream>
#include <fstream>
#include <map>
#include <format>
#include <iomanip>
using namespace std;

struct Data {
	int vrijeme;
	string ime;
};

istream& operator >>(istream& is,Data& d)
{
	return is >> d.vrijeme >> d.ime;
}
int main()
{
	map<string, int> m;
	map<int,int> v;
	ifstream f("goals.txt");
	string ime;
	int minute,sekunde;
	char c;
	while (f >> minute >> c >> sekunde >> ime)
	{
		m[ime]++;
		v[minute / 10]++;
	}
	for (auto a : v)
	{
		cout << a.first * 10 << " - " << (a.first % 10 + 1) * 10 << ": " << a.second << endl;
	}
	cout << "\n";
	for (auto a : m)
	{
		cout << a.first << " : " << a.second << endl;
	}




	return 0;
}