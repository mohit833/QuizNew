/*#include "UserManager.h"
#include "QuizManager.h"
#include "UserProgressTracker.h"
#include "AdminManager.h"
#include <iostream>
#include <string>

int main() {
    UserManager userManager;
    QuizManager quizManager;
    UserProgressTracker progressTracker;
    std::string role, username, password, action;

    std::cout << "Are you a user or admin? (user/admin): ";
    std::cin >> role;

    if (role == "admin") {
        std::cout << "Admin Username: ";
        std::cin >> username;
        std::cout << "Admin Password: ";
        std::cin >> password;
        if (AdminManager::isAdminLogin(username, password)) {
            std::cout << "Admin logged in successfully.\n";
            AdminManager::addQuiz(quizManager); // Assumes this function prompts admin for quiz details and adds it to the file
        }
        else {
            std::cerr << "Admin login failed. Please check your credentials.\n";
            return 1;
        }
    }
    else if (role == "user") {
        x:
        std::cout << "Do you want to log in or register? (login/register): ";
        std::cin >> action;

        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (action == "register") {
            userManager.registerUser(username, password);
            std::cout << "Registration successful. Please log in.\n";
        }
        
        if (userManager.authenticateUser(username, password) || action == "register") {
           
            std::cout << "Login successful.\n";

            auto quizzes = quizManager.loadQuizzes("quizz.txt");
            std::cout << "Quizzes loaded: " << quizzes.size() << "\n";

            int quizChoice;
            do {
                std::cout << "\nAvailable quizzes:\n";
                for (size_t i = 0; i < quizzes.size(); ++i) {
                    std::cout << i + 1 << ". " << quizzes[i].title << "\n";
                }
                std::cout << "Select a quiz to take (or enter 0 to exit): ";
                std::cin >> quizChoice;

                if (quizChoice > 0 && quizChoice <= quizzes.size()) {
                    int score = quizzes[quizChoice - 1].startQuiz();
                    progressTracker.updateScore(username, score, quizzes[quizChoice - 1].title);
                    std::cout << "Would you like to view your scores? (yes/no): ";
                    std::string viewScores;
                    std::cin >> viewScores;
                    if (viewScores == "yes") {
                        progressTracker.viewScores(username);
                    }
                }
            } while (quizChoice != 0);

            std::cout << "Thank you for using the Quiz Application.\n";
        }
        else {
            std::cerr << "Login failed. Please check your credentials or register if you're a new user.\n";
            goto x;
            //return 1;
            
        }
    }
    else {
        std::cerr << "Invalid role. Exiting.\n";
        return 1;
    }

    return 0;
}*/
#include "UserManager.h"
#include "QuizManager.h"
#include "UserProgressTracker.h"
#include "AdminManager.h"
#include <iostream>
#include <string>

int main() {
    UserManager userManager;
    QuizManager quizManager;
    UserProgressTracker progressTracker;
    std::string role, username, password;
    x:
    std::cout << "Are you a user or admin? (user/admin): ";
    std::cin >> role;

    if (role == "admin") {
        std::cout << "Do you want to log in or register? (login/register): ";
        std::string adminAction;
        std::cin >> adminAction;

        std::cout << "Admin Username: ";
        std::cin >> username;
        std::cout << "Admin Password: ";
        std::cin >> password;

        if (adminAction == "register") {
            AdminManager::registerAdmin(username, password);
            std::cout << "Registration successful. Admin logged in.\n";
        }
        else if (adminAction == "login") {
            if (!AdminManager::isAdminLogin(username, password)) {
                std::cerr << "Admin login failed. Please check your credentials.\n";
                goto x;
                return 1;
            }
            std::cout << "Admin login successful.\n";
        }

       
        AdminManager::addQuiz(quizManager); 

    }
    else if (role == "user") {
        y:
        std::cout << "Do you want to log in or register? (login/register): ";
        std::string userAction;
        std::cin >> userAction;

        std::cout << "Username: ";
        std::cin >> username;
        std::cout << "Password: ";
        std::cin >> password;

        if (userAction == "register") {
            userManager.registerUser(username, password);
            std::cout << "Registration successful. You're now logged in.\n";
        }
        else if (userAction == "login") {

            if (!userManager.authenticateUser(username, password)) {
                std::cerr << "Login failed. Please check your credentials.\n";
                goto y;
                return 1;
            }
            std::cout << "Login successful.\n";
        }

        
        auto quizzes = quizManager.loadQuizzes("quizz.txt");
        std::cout << "Quizzes loaded: " << quizzes.size() << "\n";

        int quizChoice = 0;
        do {
            std::cout << "\nAvailable quizzes:\n";
            for (size_t i = 0; i < quizzes.size(); ++i) {
                std::cout << i + 1 << ": " << quizzes[i].title << "\n";
            }
            std::cout << "Select a quiz to take (or enter 0 to exit): ";
            std::cin >> quizChoice;
            if (quizChoice > 0 && quizChoice <= quizzes.size()) {
                int score = quizzes[quizChoice - 1].startQuiz();
                progressTracker.updateScore(username, score, quizzes[quizChoice - 1].title);
                std::cout << "Would you like to view your scores? (yes/no): ";
                std::string viewScores;
                std::cin >> viewScores;
                if (viewScores == "yes") {
                    progressTracker.viewScores(username);
                }
            }
        } while (quizChoice != 0);
        std::cout << "Thank you for using the Quiz Application.\n";
    }
    else {
        std::cerr << "Invalid role. Exiting.\n";
        return 1;
    }

    return 0;
}
