//Napravite program za statistiku postizanja golova u rukometnoj utakmici.
//Podaci se nalaze u datoteci goals.txt(u repozitoriju) u formatu : vrijeme strijelac.
//Ispišite u kojem intervalu(po 10 minuta) je palo koliko golova i koliko je koji igrač dao golova :
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <format>
#include <iomanip>


int main() {
    std::ifstream file("goals.txt");
    
    std::map<std::string, int> goal_stats;
    std::map<int, int> interval_stats;
    int minutes;
    char time_delimiter;
    int seconds;
    std::string player;

    while (file >> minutes >> time_delimiter >> seconds >> player) {
        int interval = minutes / 10;
        interval_stats[interval]++;
        goal_stats[player]++;
    }

    file.close();

    for (int i = 0; i < 6; ++i) {
        std::cout << i * 10 << " - " << (i + 1) * 10 << ": " << interval_stats[i] << std::endl;
    }

    std::cout << std::endl;

    for (const auto& entry : goal_stats) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }
}
