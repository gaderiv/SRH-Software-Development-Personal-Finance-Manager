#include "Budgeting.h"

//private functions
int Budgeting::getDaysInMonth(int month, int year)
{

	if (month == 2) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}

}

void Budgeting::writeToCSV(const std::string& filename, const std::string& data)
{
	std::ofstream file(filename);
	if (file.is_open()) {
		file << data;
		file.close();
	}
	else {
		std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
	}
}


//public functions

Budgeting::Budgeting(int month, int year, double salary)
{
	this->month = month;
	this->year = year;
	this->salary = salary;
}

void Budgeting::generateBudgetPlan()
{
	int daysInMonth = getDaysInMonth(month, year);

	//daily budget
	double dailyBudget = salary / daysInMonth;

	//percentage budget
	double savings = 0.2 * salary;
	double mandatoryPayments = 0.4 * salary;
	double investing = 0.1 * salary;
	double unexpectedTransactions = 0.3 * salary;

	//CSV
	std::stringstream csvContent;
	csvContent << "Day, Daily Budget, Savings, Mandatory Payments, Investing, Unexpected Transactions, Total\n";
	
	for (int day = 1; day <= daysInMonth; ++day)
	{
		double dailySavings = 0.2 * dailyBudget;
		double dailyMandatoryPayments = 0.4 * dailyBudget;
		double dailyInvesting = 0.1 * dailyBudget;
		double dailyUnexpectedTransactions = 0.3 * dailyBudget;

		double dailyTotal = dailySavings + dailyMandatoryPayments + dailyInvesting + dailyUnexpectedTransactions;

		csvContent << day << ", " << std::fixed << std::setprecision(2) << dailyBudget << ", "
			<< dailySavings << ", " << dailyMandatoryPayments << ", "
			<< dailyInvesting << ", " << dailyUnexpectedTransactions << ", "
			<< dailyTotal << "\n";
	}

	std::string filename = "budgetplan.csv";
	writeToCSV(filename, csvContent.str());

	std::cout << "Budget plan generated and saved to " << filename << std::endl;
}

void Budgeting::printSummary()
{
	int daysInMonth = getDaysInMonth(month, year);

	// Calculate total allocations for the month
	double totalSavings = 0.2 * salary;
	double totalMandatoryPayments = 0.4 * salary;
	double totalInvesting = 0.1 * salary;
	double totalUnexpectedTransactions = 0.3 * salary;

	std::cout << "\nSummary for the month:\n";
	std::cout << "Total Savings: " << totalSavings << "\n";
	std::cout << "Total Mandatory Payments: " << totalMandatoryPayments << "\n";
	std::cout << "Total Investing: " << totalInvesting << "\n";
	std::cout << "Total Unexpected Transactions: " << totalUnexpectedTransactions << "\n";

	double totalBudget = totalSavings + totalMandatoryPayments + totalInvesting + totalUnexpectedTransactions;

	std::cout << "Total Monthly Budget: " << totalBudget << "\n";
}


