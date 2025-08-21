#include <iostream>
#include <fstream>
#include "bank.h"

// Load accounts from file into the map
void Bank::loadAccounts(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening accounts file." << std::endl;
        return;
    }

    int accountNumber;
    std::string name;
    double balance;

    // Read each account: accountNumber name balance
    while (file >> accountNumber >> name >> balance) {
        accounts.emplace(accountNumber, Account(accountNumber, name, balance));
    }
}

// Process transactions from a file
void Bank::processTransactions(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening transactions file." << std::endl;
        return;
    }

    int accountNumber;
    char transactionType;
    double amount;

    // Read each transaction
    while (file >> accountNumber >> transactionType >> amount) {
        auto it = accounts.find(accountNumber);
        if (it == accounts.end()) {
            std::cerr << "Account not found: " << accountNumber << std::endl;
            continue;
        }

        // Deposit transaction
        if (transactionType == 'D') it->second.deposit(amount);
        // Withdrawal transaction
        else if (transactionType == 'W') {
            if (!it->second.withdraw(amount))
                std::cerr << "Insufficient funds: " << accountNumber << std::endl;
        } 
        // Invalid transaction type
        else std::cerr << "Invalid transaction type: " << transactionType << std::endl;
    }
}

// Print all accounts with current balances
void Bank::printAccounts() const {
    for (const auto& pair : accounts) {
        const Account& account = pair.second;
        std::cout << "Account Number: " << account.getAccountNumber() << std::endl;
        std::cout << "Name: " << account.getName() << std::endl;
        std::cout << "Balance: $" << account.getBalance() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}
