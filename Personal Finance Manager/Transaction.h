#pragma once
#pragma warning(disable : 4996)

#include <ctime>
#include <string>

class Transaction
{
public:

	double amount;

	std::string category;
	std::string description;
	std::string date;

	Transaction(double amount, std::string category, std::string description);

};

