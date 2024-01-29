#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

struct Goal
{
public:
	Goal(std::string time = "", std::string shooter = "") : vrijeme(time), strijelac(shooter) {}
	std::string vrijeme;
	std::string strijelac;
};

void procesuiranjeGolova(const std::vector<Goal>& goals)
{
	std::map<std::string, int> intervaliGolova;
	std::map<std::string, int> goloviIgraca;

	for (const Goal& goal : goals)
	{
		int minute = std::stoi(goal.vrijeme.substr(0, goal.vrijeme.find(':')));
		int interval = (minute / 10) * 10;
		intervaliGolova[std::to_string(interval) + "-" + std::to_string(interval + 10)]++;
		goloviIgraca[goal.strijelac]++;
	}
	for (const auto& zapis : intervaliGolova)
	{
		std::cout << zapis.first << ": " << zapis.second << std::endl;
	}
	std::cout << std::endl;
	for (const auto& zapis : goloviIgraca)
	{
		std::cout << zapis.first << ": " << zapis.second << std::endl;
	}
}

int main()
{
	std::ifstream ulaznaDatoteka("goals.txt");
	std::vector<Goal> goals;
	std::string ucitaniPodatak;
	while (std::getline(ulaznaDatoteka, ucitaniPodatak))
	{
		std::istringstream iss(ucitaniPodatak);
		Goal goal;
		iss >> goal.vrijeme >> goal.strijelac;
		goals.push_back(goal);
	}
	ulaznaDatoteka.close();
}
