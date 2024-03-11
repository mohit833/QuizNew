#include "AdminManager.h"
#include <iostream>

/*bool AdminManager::isAdminLogin(const std::string& username, const std::string& password) {
    return username == "admin" && password == "admin"; 
}*/
#include "AdminManager.h"
#include <fstream>
#include <iostream>

void AdminManager::registerAdmin(const std::string& username, const std::string& password) {
    std::ofstream file("admins.txt", std::ios::app);
    if (file) {
        file << username << " " << password << "\n";
        std::cout << "Admin registration successful.\n";
    }
    else {
        std::cerr << "Unable to open file for appending.\n";
    }
}

bool AdminManager::isAdminLogin(const std::string& username, const std::string& password) {
    std::ifstream file("admins.txt");
    std::string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
    }
    return false;
}

void AdminManager::addQuiz(QuizManager& quizManager) {
    std::string title, questionText, option, correctAnswerStr;
    int correctAnswer;
    std::vector<Question> questions;

    std::cout << "Enter Quiz Title: ";
    std::getline(std::cin >> std::ws, title);

    char more = 'y';
    do {
        std::cout << "Enter question: ";
        std::getline(std::cin >> std::ws, questionText);

        std::vector<std::string> options;
        for (int i = 1; i <= 4; ++i) {
            std::cout << "Enter option " << i << ": ";
            std::getline(std::cin, option);
            options.push_back(option);
        }

        std::cout << "Enter correct answer index (1-4): ";
        std::cin >> correctAnswer;
        questions.push_back(Question(questionText, options, correctAnswer - 1));

        std::cout << "Add another question? (y/n): ";
        std::cin >> more;
    } while (more == 'y' || more == 'Y');

    Quiz newQuiz(title);
    for (auto& question : questions) {
        newQuiz.addQuestion(question);
    }
    quizManager.addQuizToFile(newQuiz);
}