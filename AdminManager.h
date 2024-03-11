#pragma once

/*#include "QuizManager.h"
#include<string>

class AdminManager {
public:
    static bool isAdminLogin(const std::string& username, const std::string& password);
    static void addQuiz(QuizManager& quizManager);
};
*/

#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include "QuizManager.h"
#include <string>

class AdminManager {
public:
    static void registerAdmin(const std::string& username, const std::string& password);
    static bool isAdminLogin(const std::string& username, const std::string& password);
    static void addQuiz(QuizManager& quizManager);
};

#endif // ADMINMANAGER_H
