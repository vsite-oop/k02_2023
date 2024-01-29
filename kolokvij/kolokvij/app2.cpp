
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

struct Goal {
    std::string time;
    std::string scorer;
};


std::vector<Goal> readGoals(const std::string& filename) {
    std::vector<Goal> goals;
    std::ifstream file(filename);


    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Goal goal;
        iss >> goal.time >> goal.scorer;
        goals.push_back(goal);
    }

    file.close();
    return goals;
}

void ispisiStatistiku(const std::vector<Goal>& goals) {
    std::map<int, int> timeIntervals;
    std::map<std::string, int> scorers;

    for (const Goal& goal : goals) {
        
        int time = std::stoi(goal.time);

       
        timeIntervals[(time / 10) * 10]++;

        scorers[goal.scorer]++;
    }

    for (int i = 0; i < 60; i += 10) {
        std::cout << i << " - " << i + 10 << ": " << timeIntervals[i] << std::endl;
    }

    std::cout << std::endl;

    for (const auto& scorer : scorers) {
        std::cout << scorer.first << " : " << scorer.second << std::endl;
    }
}

int main() {
    std::vector<Goal> goals = readGoals("goals.txt");

    ispisiStatistiku(goals);

    return 0;
}


