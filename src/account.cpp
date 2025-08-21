#include "account.h"

// Constructor: initialize account number, name, and balance
Account::Account(int accountNumber, const std::string& name, double balance)
    : accountNumber(accountNumber), name(name), balance(balance) {}

// Get account number
int Account::getAccountNumber() const { return accountNumber; }

// Get customer name
const std::string& Account::getName() const { return name; }

// Get current balance
double Account::getBalance() const { return balance; }

// Deposit an amount
void Account::deposit(double amount) { balance += amount; }

// Withdraw an amount; return false if insufficient funds
bool Account::withdraw(double amount) {
    if (amount > balance) return false;
    balance -= amount;
    return true;
}
