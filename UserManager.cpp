

/*void UserManager::registerUser(const std::string& username, const std::string& password) {
    std::ofstream file("UserD.txt", std::ios::app);
    file << username << " " << password << "\n";
    std::cout << "Registration successful.\n";
}

bool UserManager::authenticateUser(const std::string& username, const std::string& password) {
    std::ifstream file("UserD.txt");
    std::string uname, pwd;
    while (file >> uname >> pwd) {
        if (uname == username && pwd == password) {
            return true;
        }
    }
    return false;
}*/
#include "UserManager.h"
#include <fstream>
#include <iostream>

bool UserManager::registerUser(const std::string& username, const std::string& password) {
    std::ofstream file("UserD.txt", std::ios::app);
    if (file) {
        file << username << " " << password << "\n";
        std::cout << "Registration successful.\n";
        return true;
    }
    else {
        std::cout << "Unable to open users.txt for appending.\n";
        return false;
    }
}

bool UserManager::authenticateUser(const std::string& username, const std::string& password) {
    std::ifstream file("UserD.txt");
    std::string storedUsername, storedPassword;
    while (file >> storedUsername >> storedPassword) {
        if (storedUsername == username && storedPassword == password) {
            return true;
        }
        
            return false;
        
    }
}

