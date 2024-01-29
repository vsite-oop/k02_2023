//#include <string>
//#include <iostream>
//#include <map>
//#include <iterator>
//#include <fstream>
//#include <algorithm>
//#include <vector>
//#include <format>
//
//int main(/*int argc, char* argv[]*/) {
//	std::string path = "C:\\Faks\\OBJ\\Kolokvij\\PraviKolokvij_02\\goals.txt";
//	std::string dataName = "goals.txt";
//	std::ifstream data(path);
//	//std::string dataName = argv[1];
//
//	//std::ifstream data(dataName);
//
//	if (!data.is_open()) {
//		std::cerr << "Error opening " << dataName << std::endl;
//		return 1;
//	}
//
//	std::map<std::string, int> stats;
//	//std::map<std::string, int> minutaza;
//	std::map<int, int> minutaza;
//	char time_del;
//	std::string strijelac;
//	int min, sec;
//
//
//	//Posloziti bolje ako ima vremena
//	/*while (data >> min >> time_del >> sec >> strijelac) {
//		stats[strijelac]++;
//		if (min <= 9) {minutaza["1 - 10"]++;}
//		else if (min <= 19) { minutaza["10 - 20"]++; }
//		else if (min <= 29) { minutaza["20 - 30"]++; }
//		else if (min <= 39) { minutaza["30 - 40"]++; }
//		else if (min <= 49) { minutaza["40 - 50"]++; }
//		else { minutaza["50 - 60"]++; }
//	}*/
//
//	while (data >> min >> time_del >> sec >> strijelac) {
//		stats[strijelac]++;
//		minutaza[min / 10]++;
//	}
//
//	for (const auto& score : minutaza) {
//		std::cout << std::format("{} - {}: {}\n", score.first, score.first +10, score.second);
//	}
//	std::cout << std::endl;
//	for (const auto& score2 : stats) {
//		std::cout << std::format("{}: {}\n", score2.first, score2.second);
//	}
//}