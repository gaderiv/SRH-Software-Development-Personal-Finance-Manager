#pragma once

#include <vector>

#include "User.h"

class FinanceManager
{
private:
	User user;
	std::vector<Transaction> transactions;
	std::vector<std::string> expenseCategories;

public:

	FinanceManager(User user) : user(user)
	{
		loadTransactions();
		loadExpenseCategories();
	}

	//Methods add
	void addExpense(double amount, std::string category, std::string description);
	void addIncome(double amount, std::string description);

	//Methods i/o and gen
	void generateMonthlyReport(int month, int year);
	void saveTransactions();
	void loadTransactions();
	void loadExpenseCategories();

	//const
	const std::vector<std::string>& getExpenseCategories() const
	{
		return expenseCategories;
	}
	const std::vector<Transaction>& getTransactions() const
	{
		return transactions;
	}

	//Methods expense Catergories
	void printExpenseCategories();
	bool isCategoryValid(std::string category);

	//mathmetods
	double calculateBalance();

	//getter
	Transaction getTransaction(int index) const;

};

