#pragma once

#include "User.h"

class Budgeting
{
private:
	int month, year;
	double salary;

	int getDaysInMonth(int month, int year);
	void writeToCSV(const std::string& filename, const std::string& data);

public:
	Budgeting(int month, int year, double salary);

	void generateBudgetPlan();
	void printSummary();
};

