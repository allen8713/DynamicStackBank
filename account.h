#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

// Class representing a single bank account
class Account {
public:
    // Constructor
    Account(int accountNumber, const std::string& name, double balance);

    // Accessors
    int getAccountNumber() const;
    const std::string& getName() const;
    double getBalance() const;

    // Deposit and withdrawal functions
    void deposit(double amount);
    bool withdraw(double amount);

private:
    int accountNumber;   // Unique account number
    std::string name;    // Customer name
    double balance;      // Current account balance
};

#endif
