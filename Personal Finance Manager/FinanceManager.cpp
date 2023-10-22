#include "FinanceManager.h"

//Methods add
void FinanceManager::addExpense(double amount, std::string category, std::string description)
{
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

	std::cout << "Monthly Report for: " << month << "/" << year << std::endl;

	for (const Transaction& trans : transactions)
	{
		try {
			
			std::string date = trans.date;
			size_t slash1 = date.find('/');
			size_t slash2 = date.rfind('/');

			if (slash1 != std::string::npos && slash2 != std::string::npos)
			{
				int transMonth = std::stoi(date.substr(0, slash1));
				int transYear = std::stoi(date.substr(slash2 + 1));

				if (transMonth == month && transYear == year)
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
		}
		catch (const std::exception& e) {
			std::cerr << "Error parsing date: " << e.what() << std::endl;
		}
	}

	std::cout << "Income: " << totalIncome << " Euro" << std::endl;
	std::cout << "Expenses: " << totalExpense << " Euro" << std::endl;
	std::cout << "Balance: " << totalIncome - totalExpense << " Euro" << std::endl;
}

void FinanceManager::saveTransactions()
{
	std::ofstream file("transactions.txt");

	if (file.is_open())
	{
		for (const Transaction& trans : transactions)
		{
			file << trans.amount << ',' << trans.category << ',' << trans.description << ',' << trans.date << '\n';
		}
		file.close();
	}
}

void FinanceManager::loadTrancsactions()
{
	std::ifstream file("transactions.txt");

	if (file.is_open()) {
		double amount;
		std::string category, description, date;

		while (file >> amount) {
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
