#pragma once
#include <string>
#include <iostream>

class User
{
public:
	bool operator==(const User& obj);

	void CreateUser(const std::string&& NumberCard, int PIN);
	void deposit(int amount);
	void withdraw(int amount);
	int  GetBalance() const noexcept;
	
private:
	std::string m_NumberCard{ "" };
	int         m_PINCode{ 0 };
	int		    m_balance{ 0 };
};

