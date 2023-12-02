#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>


#include "Transaction.h"



class User
{
public:
	int age;
	double income;
	std::string name;

	User(std::string name, int age, double income);

	void displayUserInfo();

	static User createUser();
	static User loadUserFromFile();

};

