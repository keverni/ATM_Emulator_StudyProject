#include "ATM.h"

void ATM::CreateUser(const std::string&& NumberCard, int PIN)
{
	UpdateUser();
	m_CurrentUser.CreateUser(std::forward<const std::string&&>(NumberCard), PIN);
	m_ListUsers.emplace_back(m_CurrentUser);
}
bool ATM::ExistingUser(const std::string&& NumberCard, int PIN)
{
	UpdateUser();
	User obj{};
	obj.CreateUser(std::forward<const std::string&&>(NumberCard), PIN);
	for (auto& elem : m_ListUsers)
	{
		if (elem == obj)
		{
			m_CurrentUser = elem;
			return true;
		}
	}
	return false;
}
void ATM::deposit(int amount)
{
	m_CurrentUser.deposit(amount);
}
void ATM::withdraw(int amount)
{
	m_CurrentUser.withdraw(amount);
}
int  ATM::GetBalance() const noexcept
{
	return m_CurrentUser.GetBalance();
}


void ATM::UpdateUser()
{
	if (!m_ListUsers.empty())
	{
		for (auto& elem : m_ListUsers)
		{
			if (elem == m_CurrentUser)
			{
				elem = m_CurrentUser;
			}
		}
	}
}

