#pragma once

#include <vector>

#include "User.h"

class FinanceManager
{
private:
	User user;
	std::vector<Transaction> transactions;

public:

	FinanceManager(User user) : user(user)
	{
		loadTrancsactions();
	}

	//Methods add
	void addExpense(double amount, std::string category, std::string description);
	void addIncome(double amount, std::string description);

	//Methods i/o and gen
	void generateMonthlyReport(int month, int year);
	void saveTransactions();
	void loadTrancsactions();

	//mathmetods
	double calculateBalance();

};

