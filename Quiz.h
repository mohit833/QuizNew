#pragma once
#pragma once
#ifndef QUIZ_H
#define QUIZ_H

#include "Question.h"
#include <vector>
#include <string>

class Quiz {
public:
    std::vector<Question> questions;
    std::string title;

    Quiz(std::string t);
    void addQuestion(const Question& question);
    int startQuiz();
};

#endif 