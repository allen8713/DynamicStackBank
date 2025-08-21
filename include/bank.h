#ifndef BANK_H
#define BANK_H

#include <string>
#include <unordered_map>
#include "account.h"

// Class representing a bank with multiple accounts
class Bank {
public:
    // Load accounts from a file
    void loadAccounts(const std::string& filename);

    // Process transactions from a file
    void processTransactions(const std::string& filename);

    // Print all accounts
    void printAccounts() const;

private:
    std::unordered_map<int, Account> accounts; // Map of account number to Account
};

#endif
