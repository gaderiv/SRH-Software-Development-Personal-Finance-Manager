#pragma once

#include "PFMLib/User.h"
#include "PFMLib/FinanceManager.h"
#include "PFMLib/Budgeting.h"

void menu();

void save_and_exit(FinanceManager& financeManager);

void monthly_report(int& month, int& year, FinanceManager& financeManager, int& retFlag);

void Balance(FinanceManager& financeManager);

void adding_income(double& income, std::string& incomeDescription, FinanceManager& financeManager, int& retFlag);

void adding_Expense(double& amount, FinanceManager& financeManager, int& categoryChoice, std::string& category, std::string& description, int& retFlag);

void user_creation(User& user, FinanceManager& financeManager);

void generate_budget_plan(int& month, int& year, double& salary);
