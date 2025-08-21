#include "bank.h"

int main() {
    Bank bank;

    // Load accounts from file
    bank.loadAccounts("accounts.txt");

    // Print account info before transactions
    bank.printAccounts();

    // Process transactions
    bank.processTransactions("transactions.txt");

    // Print account info after transactions
    bank.printAccounts();

    return 0;
}
