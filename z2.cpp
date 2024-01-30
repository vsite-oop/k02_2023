#include <iostream>
#include <map>
#include <fstream>
#include <format>
using namespace std;

int main() {
	ifstream f("goals.txt");
	map<string, int> players;
	map<int, int> intervals;
	string name;
	int min, sec;
	char c;
	while (f >> min >> c >> sec >> name) {
		players[name]++;
		intervals[min/10]++;
	}
	for (const auto [min, goals] : intervals)
		cout << format("{} - {}: {}", 10*min, 10*(min+1), goals) << '\n';
	cout << '\n';
	for (const auto [name, goals] : players)
		cout << format("{}: {}", name, goals) << '\n';
}
