/*#include "QuizManager.h"
#include "Question.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Quiz> QuizManager::loadQuizzes(const std::string& filename) {
    std::vector<Quiz> quizzes;
    std::ifstream file(filename);
    std::string line, title;
    Quiz* currentQuiz = nullptr;

    while (getline(file, line)) {
        if (line.substr(0, 11) == "Quiz Title:") {
            if (currentQuiz != nullptr) {
                quizzes.push_back(*currentQuiz);
                delete currentQuiz;
            }
            title = line.substr(11);
            currentQuiz = new Quiz(title);
        }
        else if (currentQuiz && !line.empty()) {
            std::istringstream iss(line);
            std::string questionText, optionText, correctAnsStr;
            getline(iss, questionText, '|');
            getline(iss, optionText, '|');
            getline(iss, correctAnsStr);
            std::vector<std::string> options;
            std::istringstream opts(optionText);
            std::string opt;
            while (getline(opts, opt, ',')) {
                options.push_back(opt);
            }
            int correctAnswer = std::stoi(correctAnsStr) - 1;

            currentQuiz->addQuestion(Question(questionText, options, correctAnswer));
        }
    }
    if (currentQuiz != nullptr) {
        quizzes.push_back(*currentQuiz);
        delete currentQuiz;
    }
    return quizzes;
}*/

#include "QuizManager.h"
#include "Question.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Quiz> QuizManager::loadQuizzes(const std::string& filename) {
    std::vector<Quiz> quizzes;
    std::ifstream file(filename);
    std::string line, title;
    Quiz* currentQuiz = nullptr;

    while (getline(file, line)) {
        if (line.substr(0, 11) == "Quiz Title:") {
            if (currentQuiz != nullptr) {
                quizzes.push_back(*currentQuiz);
                delete currentQuiz;
            }
            title = line.substr(11);
            currentQuiz = new Quiz(title); // Ensure Quiz constructor exists and is accessible
        }
        else if (currentQuiz && !line.empty()) {
            std::istringstream iss(line);
            std::string questionText, optionText, correctAnsStr;
            getline(iss, questionText, '|');
            getline(iss, optionText, '|');
            getline(iss, correctAnsStr);
            std::vector<std::string> options;
            std::istringstream opts(optionText);
            std::string opt;
            while (getline(opts, opt, ',')) {
                options.push_back(opt);
            }
            int correctAnswer = std::stoi(correctAnsStr) - 1;

            currentQuiz->addQuestion(Question(questionText, options, correctAnswer)); // Ensure Question constructor exists and is accessible
        }
    }
    if (currentQuiz != nullptr) {
        quizzes.push_back(*currentQuiz);
        delete currentQuiz;
    }
    file.close();
    return quizzes;
}

void QuizManager::addQuizToFile(const Quiz& quiz) {
    std::ofstream file("quizz.txt", std::ios::app); 

    if (!file.is_open()) {
        std::cerr << "Failed to open quizzes.txt for appending.\n";
        return;
    }

    file << "\nQuiz Title:" << quiz.title << "\n";
    for (const auto& question : quiz.questions) {
        file << question.text << "|";
        for (size_t i = 0; i < question.options.size(); ++i) {
            file << question.options[i];
            if (i < question.options.size() - 1) file << ",";
        }
        file << "|" << question.correctAnswer + 1 << "\n";
    }

    file.close();
}