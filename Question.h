#pragma once
#pragma once
#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <vector>

class Question {
public:
    std::string text;
    std::vector<std::string> options;
    int correctAnswer;

    Question(std::string qText, std::vector<std::string> opts, int correct);
};

#endif 