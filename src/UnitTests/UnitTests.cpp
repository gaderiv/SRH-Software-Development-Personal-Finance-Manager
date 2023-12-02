#include "gtest/gtest.h"

#include "/test/Personal Finance Manager/src/PFMLib/FinanceManager.h"

TEST(FinanceManagerTest, AddExpense) 
{
    User user("MyTESTER", 25, 0);
    FinanceManager financeManager(user);

    financeManager.addExpense(50, "Food", "Groceries");

    //Checker for transaction
    ASSERT_EQ(1, financeManager.getTransactions().size());

    //Checker for correctness
    Transaction expense = financeManager.getTransaction(0);
    ASSERT_EQ(-50, expense.amount);
    ASSERT_EQ("Food", expense.category);
    ASSERT_EQ("Groceries", expense.description);
}

TEST(FinanceManagerTest, AddIncome) 
{
    User user("MyTESTER", 25, 0);
    FinanceManager financeManager(user);

    financeManager.addIncome(1000, "Salary");

    //Checker for transaction
    ASSERT_EQ(1, financeManager.getTransactions().size());

    //Checker for correctness
    Transaction income = financeManager.getTransaction(0);
    ASSERT_EQ(1000, income.amount);
    ASSERT_EQ("Income", income.category);
    ASSERT_EQ("Salary", income.description);
}

TEST(FinanceManagerTest, CalculateBalance) 
{
    User user("MyTESTER", 25, 0);
    FinanceManager financeManager(user);

    financeManager.addIncome(2000, "Salary");
    financeManager.addExpense(500, "Food", "Groceries");

    //Checker for correctness
    ASSERT_EQ(2000 - 500, financeManager.calculateBalance());
}

int main(int argc, char** argv) 
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
