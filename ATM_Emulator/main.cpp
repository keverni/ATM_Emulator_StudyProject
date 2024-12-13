#include <iostream>
#include <string>
#include "ATM.h"

std::string InputString(const std::string& caption) noexcept
{
	std::cout << caption;

	std::string value{};

	while (value.empty())
	{
		std::getline(std::cin, value);
	}

	return value;
}

void NewUser(ATM&& atm)
{
	auto NumberCard{ InputString("Enter NumberCard for registrations: ") };
	auto PIN{ 0 };

	std::cout << std::endl;

	while (true)
	{
		std::cout << "Enter your PIN-code for registrations: ";
		std::cin >> PIN;
		if (PIN % 1000 != 0)
		{
			break;
		}
		else
		{
			std::cout << "Incorrect PIN-code. It must consist of 4 digits!" << std::endl;
			continue;
		}
	}
	
	atm.CreateUser(std::forward<const std::string&&>(NumberCard), PIN);
}

int main()
{
	std::cout << "Hi! It's ATM.";
	ATM atm{};
	NewUser(std::forward<ATM&&>(atm));
	auto Choose{ 0 };

	while (true)
	{
		std::cout << "Choose option: 1 - Deposit, 2 - Withdraw, 3 - Create new user, 4 - Show balance,  5 - Enter to existing user, 6 - exit" << std::endl;
		std::cin >> Choose;
		if (Choose == 1)
		{
			auto amount{ 0 };
			std::cout << "Enter amount to deposit: ";
			std::cin >> amount;
			atm.deposit(amount);
		}
		else if (Choose == 2)
		{
			auto amount{ 0 };
			std::cout << "Enter amount to withdraw: ";
			std::cin >> amount;
			atm.withdraw(amount);
		}
		else if (Choose == 3)
		{
			NewUser(std::forward<ATM&&>(atm));
		}
		else if (Choose == 4)
		{
			std::cout << "Your balance: " << atm.GetBalance() << std::endl;
		}
		else if (Choose == 5)
		{
			auto NumberCard{ InputString("Enter NumberCard to login: ")};
			auto Pin{ 0 };

			std::cout << std::endl;

			std::cout << "Enter PIN-code to login: ";
			std::cin >> Pin;

			if (atm.ExistingUser(std::move(NumberCard), Pin))
			{
				std::cout << "Good!!! You are welcome!" << std::endl;
				continue;
			}
			else
			{
				std::cout << "We can't find your account!";
				continue;
			}
		}
		else if (Choose == 6)
		{
			break;
		}
	}

	return 0;
}