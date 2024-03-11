#pragma once
#pragma once
#ifndef USERPROGRESSTRACKER_H
#define USERPROGRESSTRACKER_H

#include <string>

class UserProgressTracker {
public:
    void updateScore(const std::string& username, int score, const std::string& quizTitle);
    void viewScores(const std::string& username);
};

#endif 