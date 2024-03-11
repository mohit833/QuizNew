#pragma once
#pragma once
#ifndef USERMANAGER_H
#define USERMANAGER_H
#include<string>
class UserManager {
public:
	bool registerUser(const std::string& username, const std::string& password);
	bool authenticateUser(const std::string& username, const std::string& password);
};
#endif