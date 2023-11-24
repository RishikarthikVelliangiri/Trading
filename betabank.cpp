#include <iostream>
using namespace std;

void makeDeposit(int &account, int &amount) {
    account = account + amount;
}

void makeWithdrawal(int &account, int &amount) {
    int checker = account - amount;
    if (checker > 10000) {
        account = account - amount;
    } else {
        cout << "Funds will be less than 10000 in the DMAT.";
    }
}

void saveTransaction(int &account) {
    int choice = 1;
    int transactionType = 0;
    int transactions[100];
    int accountBalance[100];
    int transactionCounter = 0;
    int transactionAmount;

    while (choice == 1) {
        cout << "Withdraw(1), Deposit(2), DMAT Account Balance(3), End(4): ";
        cin >> transactionType;

        if (transactionType == 1) {
            cout << endl << "Enter withdrawal amount: ";
            cin >> transactionAmount;
            makeWithdrawal(account, transactionAmount);
            transactions[transactionCounter] = transactionAmount * -1;
            accountBalance[transactionCounter] = account;
            transactionCounter++;
            cout << endl;
        } else if (transactionType == 2) {
            cout << endl << "Enter deposit amount: ";
            cin >> transactionAmount;
            makeDeposit(account, transactionAmount);
            transactions[transactionCounter] = transactionAmount;
            accountBalance[transactionCounter] = account;
            transactionCounter++;
            cout << endl;
        } else if (transactionType == 3) {
            cout << endl << "Type" << "         " << "Amount" << "         " << "Account Balance" << endl << endl;
            for (int i = 0; i < transactionCounter; i++) {
                if (transactions[i] >= 0) {
                    cout << "Deposit " << "         " << transactions[i] << "         " << accountBalance[i] << endl;
                } else {
                    cout << "Withdrawal" << "      " << transactions[i] << "         " << accountBalance[i] << endl;
                }
            }
            cout << endl;
        } else if (transactionType == 4) {
            choice = 0;
        }
    }
}

int main() {
    int currentAccount = 50000;
    saveTransaction(currentAccount);
    return 0;
}
