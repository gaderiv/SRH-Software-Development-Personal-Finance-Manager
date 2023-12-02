cmake_minimum_required(VERSION 3.28)

project("Personal_Finance_Manager")

add_executable(${PROJECT_NAME} "main.cpp"
                                "main.h"
                                "FinanceManager.cpp"
                                "FinanceManager.h"
                                "User.cpp"
                                "User.h"
                                "Transaction.cpp"
                                "Transaction.h"
                                "Budgeting.cpp"
                                "Budgeting.h"
                                "budgetplan.csv"
                                "transactions.csv"
                                "users.csv"
)

add_subdirectory(SRC/UnitTests)