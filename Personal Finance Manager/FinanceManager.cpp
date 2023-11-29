#include "FinanceManager.h"

//Methods added
void FinanceManager::addExpense(double amount, std::string category, std::string description)
{
	if (!isCategoryValid(category))
	{
		std::cout << "Invalid category. Please choose a valid category\n";
		return;
	}

	Transaction expense(-amount, category, description);
	transactions.push_back(expense);
}

void FinanceManager::addIncome(double amount, std::string description)
{
	Transaction income(amount, "Income", description);
	transactions.push_back(income);
}

//Methods i/o and gen
void FinanceManager::generateMonthlyReport(int month, int year)
{
	double totalIncome = 0, totalExpense = 0;

	system("cls");

	std::cout << "Monthly Report for: " << std::setfill('0') << std::setw(2) << month << "/" << year << std::endl;

	for (const Transaction& trans : transactions)
	{
		try 
		{
			std::tm tm = {};
			std::istringstream dateStream(trans.date);
			dateStream >> std::get_time(&tm, "%a %b %d %H:%M:%S %Y");

			if (tm.tm_mon + 1 == month && tm.tm_year + 1900 == year)
			{
				if (trans.amount > 0)
				{
					totalIncome += trans.amount;
				}
				else
				{
					totalExpense -= trans.amount;
				}
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Error parsing date: " << e.what() << std::endl;
		}
	}

	std::cout << "Income: " << std::fixed << std::setprecision(2) << totalIncome << " Euro" << std::endl;
	std::cout << "Expenses: " << std::fixed << std::setprecision(2) << totalExpense << " Euro" << std::endl;
	std::cout << "Balance: " << std::fixed << std::setprecision(2) << totalIncome - totalExpense << " Euro" << std::endl;
}

void FinanceManager::saveTransactions()
{
	std::ofstream file("transactions.csv");

	if (file.is_open())
	{
		for (const Transaction& trans : transactions)
		{
			file << trans.amount << ',' << trans.category << ',' << trans.description << ',' << trans.date << '\n';
		}
		file.close();
	}
}

void FinanceManager::loadTransactions()
{
	std::ifstream file("transactions.csv");

	if (file.is_open()) {
		double amount;
		std::string category, description, date;

		while (file >> amount) 
		{
			file.ignore();
			std::getline(file, category, ',');
			std::getline(file, description, ',');
			std::getline(file, date);

			Transaction trans(amount, category, description);
			trans.date = date;
			transactions.push_back(trans);
		}

		file.close();
	}
}

void FinanceManager::loadExpenseCategories()
{
	expenseCategories = { "Food", "Transportation", "Enterteinment", "Utilities", "Other" };
}

//Methods expense Catergories

void FinanceManager::printExpenseCategories()
{
	int n = 0;

	std::cout << "Expense Categories:\n";
	for (const auto& category : expenseCategories)
	{
		std::cout << ++n << "." << category << '\n';
	}
}

bool FinanceManager::isCategoryValid(std::string category)
{
	return std::find(expenseCategories.begin(), expenseCategories.end(), category) != expenseCategories.end();
}


//mathmetods
double FinanceManager::calculateBalance()
{
	double balance = user.income;

	for (const Transaction& trans : transactions)
	{
		balance += trans.amount;
	}

	return balance;
}
