// Transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "include_statements.hpp"

class Transaction {
private:
    double account;
    vector<double> transactions;
    vector<double> accountBalances;

    bool makeWithdrawal(double amount);

public:
    Transaction();
    Transaction(double initialBalance);

    void makeDeposit(double amount);
    void saveTransaction(int transactionType, double transactionAmount);
    void displayTransactionHistory() const;
    double getCurrentBalance() const;
};

#endif
