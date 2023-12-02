#include "User.h"

User::User(std::string name, int age, double income)
{
    this->name = name;
    this->age = age;
    this->income = income;
}

void User::displayUserInfo()
{
    std::cout << "\nUser Information:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Age: " << age << "\n";
}

User User::createUser()
{
    int userAge;
    std::string userName;


    std::cin.ignore();

    std::cout << "Enter your name: ";
    std::getline(std::cin, userName);

    std::cout << "Enter your age: ";
    while (!(std::cin >> userAge) || userAge < 0 || userAge > 150)
    {
        std::cout << "Invalid age. Please enter a valid age: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::ofstream file("users.csv");

    if (file.is_open())
    {
        file << userName << "\n" << userAge;
        file.close();
        std::cout << "User information has been saved\n";
    }
    else
    {
        std::cout << "Error saving to the file\n";
    }

    return User(userName, userAge, 0);
}

User User::loadUserFromFile()
{
    int userAge;
    std::string userName;
    std::ifstream file("users.csv");

    if (file.is_open())
    {
        
        if (file >> userName >> userAge)
        {
            file.close();
            return User(userName, userAge, 0); 
        }
        else
        {
            std::cout << "Error reading user information from file.\n";
            file.close();
        }
    }
    else
    {
        std::cout << "Error opening file.\n";
    }

    return User("Default User", 0, 0); 
}

