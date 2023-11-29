#include "User.h"
#include "FinanceManager.h"
#include "main.h"
#include "Budgeting.h"

using namespace std;

void menu()
{
    cout << "\nPersonal Finance Manager Menu:\n";
    cout << "1. Add Expense\n";
    cout << "2. Add Income\n";
    cout << "3. Calculate Balance\n";
    cout << "4. Generate Monthly Report\n";
    cout << "5. Budget Plan\n";
    cout << "6. Create User\n";
    cout << "7. Save and Quit\n";
    cout << "Enter your choice: ";
}

void save_and_exit(FinanceManager& financeManager)
{
    financeManager.saveTransactions();
    cout << "Transactions saved. Goodbye!\n";
}

void monthly_report(int& month, int& year, FinanceManager& financeManager, int& retFlag)
{
    retFlag = 1;

    system("cls");
    cout << "Enter the month (1-12): ";

    if (!(cin >> month) || month < 1 || month > 12)
    {
        cout << "Invalid input for month. Please enter a valid month (1-12).\n";
        { retFlag = 2; return; };
    }

    cout << "Enter the year: ";

    if (!(cin >> year))
    {
        cout << "Invalid input for year. Please enter a valid number.\n";
        { retFlag = 2; return; };
    }

    financeManager.generateMonthlyReport(month, year);
}

void Balance(FinanceManager& financeManager)
{
    system("cls");
    cout << "Current Balance: " << financeManager.calculateBalance() << " Euro" << endl;
}

void adding_income(double& income, std::string& incomeDescription, FinanceManager& financeManager, int& retFlag)
{
    retFlag = 1;

    system("cls");
    cout << "Enter income amount: ";

    if (!(cin >> income))
    {
        cout << "Invalid input for income. Please enter a valid number.\n";
        { retFlag = 2; return; };
    }

    cin.ignore();
    cout << "Enter income description: ";
    getline(cin, incomeDescription);

    system("cls");
    financeManager.addIncome(income, incomeDescription);
    cout << "Income added successfully.\n";
}

void adding_Expense(double& amount, FinanceManager& financeManager, int& categoryChoice, std::string& category, std::string& description, int& retFlag)
{
    retFlag = 1;

    system("cls");
    cout << "Enter expense amount: ";

    if (!(cin >> amount))
    {
        cout << "Invalid input for amount. Please enter a valid number.\n";
        { retFlag = 2; return; };
    }

    cin.ignore();

    financeManager.printExpenseCategories();

    cout << "Choose an expense category (enter the corresponding number): ";

    if (!(cin >> categoryChoice) || categoryChoice < 1 || categoryChoice > financeManager.getExpenseCategories().size())
    {
        cout << "Invalid category choice. Please enter a valid number.\n";
        { retFlag = 2; return; };
    }

    category = financeManager.getExpenseCategories()[categoryChoice - 1];

    cin.ignore();

    cout << "Enter expense description: ";
    getline(cin, description);

    system("cls");
    financeManager.addExpense(amount, category, description);
    cout << "Expense added successfully.\n";
}

void loadUser(User& user)
{
    ifstream file("users.csv");

    if (file.is_open())
    {
        getline(file, user.name);
        file.close();
    }
}

void user_creation(User& user, FinanceManager& financeManager)
{
    user = User::createUser();
    financeManager = FinanceManager(user);
}

void generate_budget_plan(int& month, int& year, double& salary)
{
    system("cls");
    cout << "Enter month (1-12): ";

    if (!(cin >> month))
    {
        cout << "Invalid input for month. Please enter a valid number.\n";
    }

    cin.ignore();
    cout << "Enter year: ";
    if (!(cin >> year))
    {
        cout << "Invalid input for year. Please enter a valid number.\n";
    }

    cin.ignore();
    cout << "Enter monthly salary: ";
    if (!(cin >> salary))
    {
        cout << "Invalid input for salary. Please enter a valid number.\n";
    }

    system("cls");
    Budgeting budget(month, year, salary);
    budget.generateBudgetPlan();
    budget.printSummary();
}

int main()
{
    User user = User::loadUserFromFile();

    int choice, month, year, categoryChoice, retFlag;
    double income, amount, salary;
    string incomeDescription, category, description;

	FinanceManager financeManager(user);


	do
	{
        user.displayUserInfo();

        menu();
       
        //input checker
		if (!(cin >> choice))
		{
			cout << "Invalid input. Please enter a number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (choice)
		{
        //adding expence
		case 1:
		{
            adding_Expense(amount, financeManager, categoryChoice, category, description, retFlag);
            if (retFlag == 2) break;
			break;
		}

        //adding income
        case 2: 
        {
            adding_income(income, incomeDescription, financeManager, retFlag);
            if (retFlag == 2) break;
            break;
        }

        //balance
        case 3:
        {
            Balance(financeManager);
            break;
        }
        //monthly report
        case 4: 
        {
            monthly_report(month, year, financeManager, retFlag);
            if (retFlag == 2) break;
            break;
        }
        //budget planning
        case 5:
        {
            generate_budget_plan(month, year, salary);
            break;
        }
        //create user
        case 6:
        {
            user_creation(user, financeManager);
            break;
        }
        //exit and save
        case 7:
        {
            save_and_exit(financeManager);
            break;
        }
        //eventhandler
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

}