#include "UserProgressTracker.h"
#include <fstream>
#include <iostream>

void UserProgressTracker::updateScore(const std::string& username, int score, const std::string& quizTitle) {
    std::ofstream file("sco.txt", std::ios::app);
    file << username << " scored " << score << " on " << quizTitle << "\n";
}

void UserProgressTracker::viewScores(const std::string& username) {
    std::ifstream file("sco.txt");
    std::string line;
    std::cout << "Scores for " << username << ":\n";
    while (getline(file, line)) {
        if (line.find(username) != std::string::npos) {
            std::cout << line << "\n";
        }
    }
}

