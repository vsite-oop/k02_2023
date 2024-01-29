#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <format>


struct Goal {
    int min;
    int sec;
    std::string strijelac;
};

std::istream& operator>>(std::istream& is, Goal& goal) {
    char c;
    is >> goal.min >> c >> goal.sec >> goal.strijelac;
    return is;
}

int main(const int argc, const char* argv[]) {
    std::ifstream file(argv[1]);
    std::istream_iterator <Goal> file_start(file), file_end;

    std::vector<Goal> goals;
    std::map<int, int> intervals;
    std::map<std::string, int> players;

    std::copy(file_start, file_end, std::back_inserter(goals));

    for (auto const &goal : goals) {
        players[goal.strijelac]++;

        int dest = goal.min / 10;
        intervals[dest]++;
    }

    for (auto const& interval : intervals) {
        std::cout << std::format("{}-{}: {}\n", interval.first * 10, (interval.first +1) * 10, interval.second);
    }

    for (auto const& player : players) {
        std::cout << std::format("{}: {}\n", player.first, player.second);
    }
}