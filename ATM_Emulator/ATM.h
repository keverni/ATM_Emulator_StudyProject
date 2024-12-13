#pragma once
#include "User.h"
#include <string>
#include <vector>
#include <iterator>

class ATM
{
public:

	void CreateUser(const std::string&& NumberCard, int PIN);
	bool ExistingUser(const std::string&& NumberCard, int PIN);
	void deposit(int amount);
	void withdraw(int amount);
	int  GetBalance() const noexcept;

private:
	void UpdateUser();

private:
	std::vector<User> m_ListUsers{};
	User              m_CurrentUser{};
};

