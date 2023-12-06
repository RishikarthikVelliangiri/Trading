// Transaction.cpp
#include "Transaction.hpp"

Transaction::Transaction(){}

Transaction::Transaction(double initialBalance) : account(initialBalance) {
    transactions.push_back(initialBalance);
    accountBalances.push_back(initialBalance);
}

bool Transaction::makeWithdrawal(double amount) {
    if (account - amount >= 10000) {
        account -= amount;
        return true;
    } else {
        cout << "Funds will be less than 10000 in the DMAT account." << endl;
        return false;
    }
}

void Transaction::makeDeposit(double amount) {
    account += amount;
    transactions.push_back(amount);
    accountBalances.push_back(account);
}

void Transaction::saveTransaction(int transactionType, double transactionAmount) {
    if (transactionType == 1) {
        if (makeWithdrawal(transactionAmount)) {
            transactions.push_back(transactionAmount * -1);
            accountBalances.push_back(account);
        }
    } else if (transactionType == 2) {
        makeDeposit(transactionAmount);
    }
}

void Transaction::displayTransactionHistory() const {
    cout << "\nType         Amount         Account Balance\n\n";
    for (size_t i = 0; i < transactions.size(); i++) {
        if (transactions[i] >= 0) {
            cout << "Deposit      " << transactions[i] << "              " << accountBalances[i] << endl;
        } else {
            cout << "Withdrawal   " << transactions[i] << "              " << accountBalances[i] << endl;
        }
    }
    cout << endl;
}

double Transaction::getCurrentBalance() const {
    return account;
}
