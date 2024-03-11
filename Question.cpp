#include "Question.h"

Question::Question(std::string qText, std::vector<std::string> opts, int correct) :
	text(std::move(qText)), options(std::move(opts)), correctAnswer(correct) {}