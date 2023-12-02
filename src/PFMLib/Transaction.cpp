#include "Transaction.h"

Transaction::Transaction(double amount, std::string category, std::string description)
{
    this->amount = amount;
    this->category = category;
    this->description = description;

    time_t now = time(0);
    this->date = ctime(&now);
}
