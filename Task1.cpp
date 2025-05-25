/*
TODO: Write a function that accepts two arrays of players and returns an array of the players who play in both sports
Optimize the function so that it can run just O(N + M)
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

struct Player {
    string fName;
    string lName;
    string team;

    //Compares players based on their full name
    bool operator == (const Player& other) const {
        return fName == other.fName && lName == other.lName;
    }
};

//Hash Function for Players
struct PlayerHash {
    size_t operator()(const Player& p) const {
        return hash<string>()(p.fName) ^ hash<string>()(p.lName);
    }
};

//Function to find the common players between each sport
vector<Player> findCommonPlayers(const vector<Player>& bBall, const vector<Player>& fBall) {
    unordered_set<Player, PlayerHash> bBall_set(bBall.begin(), bBall.end());

    vector<Player> result;
    for (const auto& player : fBall) {
        if (bBall_set.find(player) != bBall_set.end()) {
            result.push_back(player);
        }
    }
    return result;
}

int main() {
    vector<Player> basketball_players = {
        {"Jill", "Huang", "Gators"},
        {"Janko", "Barton", "Sharks"},
        {"Wanda", "Vakulskas", "Sharks"},
        {"Jill", "Moloney", "Gators"},
        {"Luuk", "Watkins", "Gators"}
    };

    vector<Player> football_players = {
        {"Hanzla", "Radosti", "32ers"},
        {"Tina", "Watkins", "Barleycorns"},
        {"Alex", "Patel", "32ers"},
        {"Jill", "Huang", "Barleycorns"},
        {"Wanda", "Vakulskas", "Barleycorns"}
    };

    vector<Player> playsBothSports = findCommonPlayers(basketball_players, football_players);

    cout << "Players that play both Basketball and Football are: \n";
    for (const auto& p : playsBothSports) {
        cout << "* " << p.fName << " " << p.lName <<"\n";
    }

    return 0;
}