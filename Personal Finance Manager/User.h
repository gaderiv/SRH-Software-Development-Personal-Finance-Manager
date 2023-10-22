#pragma once

#include <iostream>
#include <fstream>


#include "Transaction.h"

class User
{
public:
	std::string name;
	int age;
	double income;

	User(std::string name, int age, double income);
};

