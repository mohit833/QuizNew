#pragma once
#pragma once
#ifndef QUIZMANAGER_H
#define QUIZMANAGER_H

#include "Quiz.h"
#include<vector>
#include<string>
class QuizManager {
public:
	std::vector<Quiz>loadQuizzes(const std::string& filename);

	void addQuizToFile(const Quiz& quiz);
};
#endif