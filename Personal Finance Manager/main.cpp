#include "User.h"
#include "FinanceManager.h"

using namespace std;

int main()
{
    int choice;

	User user("Michal Witwicki", 0, 0); //working on functionality
	FinanceManager financeManager(user);

	do
	{
        cout << "\nPersonal Finance Manager Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. Add Income\n";
        cout << "3. Calculate Balance\n";
        cout << "4. Generate Monthly Report\n";
        cout << "5. Save and Quit\n";
        cout << "Enter your choice: ";
       
		if (!(cin >> choice))
		{
			cout << "Incalid input. Please enter a number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		switch (choice)
		{

		case 1:
		{
			double amount;
			string category, description;
            int categoryChoice;

			cout << "Enter expense amount: ";

			if (!(cin >> amount))
			{
				cout << "Invalid input for amount. Please enter a valid number.\n";
				break;
			}
			
			cin.ignore();

            financeManager.printExpenseCategories();

            cout << "Choose an expense category (enter the corresponding number): ";

            if (!(cin >> categoryChoice) || categoryChoice < 1 || categoryChoice > financeManager.getExpenseCategories().size())
            {
                cout << "Invalid category choice. Please enter a valid number.\n";
                break;
            }

            category = financeManager.getExpenseCategories()[categoryChoice - 1];

            cin.ignore();

			cout << "Enter expense description: ";
			getline(cin, description);

			financeManager.addExpense(amount, category, description);
			cout << "Expense added successfully.\n";
			break;
		}

        case 2: 
        {
            double income;
            string incomeDescription;

            cout << "Enter income amount: ";

            if (!(cin >> income)) 
            {
                cout << "Invalid input for income. Please enter a valid number.\n";
                break;
            }

            cin.ignore();
            cout << "Enter income description: ";
            getline(cin, incomeDescription);

            financeManager.addIncome(income, incomeDescription);
            cout << "Income added successfully.\n";
            break;
        }

        case 3:
            cout << "Current Balance: $" << financeManager.calculateBalance() << endl;
            break;

        case 4: 
        {
            int month, year;

            cout << "Enter the month (1-12): ";

            if (!(cin >> month) || month < 1 || month > 12) 
            {
                cout << "Invalid input for month. Please enter a valid month (1-12).\n";
                break;
            }

            cout << "Enter the year: ";

            if (!(cin >> year)) 
            {
                cout << "Invalid input for year. Please enter a valid number.\n";
                break;
            }

            financeManager.generateMonthlyReport(month, year);
            break;
        }

        case 5:
            financeManager.saveTransactions();
            cout << "Transactions saved. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

}