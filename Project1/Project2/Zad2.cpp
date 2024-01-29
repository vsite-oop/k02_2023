#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>


int main() {
	std::map<int, int> goalIntervals;

	std::map<std::string, int> playerGoals;

	std::ifstream file("goals.txt");

	std::string line;
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string time, player;

		ss >> time;
		std::getline(ss, player);
		int minute = std::stoi(time);
		int interval = minute / 10;
			goalIntervals[interval]++;
			playerGoals[player]++;
	}

	for (int i = 0;i < 6;++i) {
		std::cout << i * 10 << "-" << (i + 1) * 10 << ": " << goalIntervals[i] << std::endl;
	}
	for (const auto& ul : playerGoals) {
		std::cout << ul.first << ": " << ul.second << std::endl;
	};
}