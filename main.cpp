// main.cpp
#include "include_statements.hpp"
#include "Fetch_User_Data.hpp"
#include "Transaction.hpp"
#include "Transaction.cpp"
#include "Fetch_User_Data.cpp"

int main() {
    string userName, password;
    int age;
    double deposit;

    cout << "Enter your name: ";
    cin >> userName;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter the amount you would like to deposit: ";
    cin >> deposit;

    // Create Transaction object with the initial balance set to the deposit
    Transaction transaction(deposit);

    // Display starting balance
    cout << "Starting Balance: " << transaction.getCurrentBalance() << "\n\n";

    // Create Fetch_User_Data object and set user data
    Fetch_User_Data user;
    user.setUserData(userName, password, age, deposit);

    int transactionType = 0;
    double transactionAmount;

    while (transactionType != 4) {
        cout << "Withdraw(1), Deposit(2), DMAT Account Balance(3), End(4): ";
        cin >> transactionType;

        if (transactionType == 3) {
            transaction.displayTransactionHistory();
        } else if (transactionType == 4) {
            break;
        } else if (transactionType == 2 || transactionType == 1){
            cout << "Enter transaction amount: ";
            cin >> transactionAmount;
            transaction.saveTransaction(transactionType, transactionAmount);
        } else {
            cout << "Enter 1, 2, 3 or 4!" << endl;
        }
    }

    return 0;
}
