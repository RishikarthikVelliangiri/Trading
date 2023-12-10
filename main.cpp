#include "include_statements.hpp"
#include "Fetch_User_Data.hpp"
#include "Transaction.hpp"
#include "Company.hpp"
#include "Transaction.cpp"
#include "Fetch_User_Data.cpp"
#include "Company.cpp"

int main() {
    string userName, password;
    string age, userID;
    double deposit;

    vector<double> analysis;
// Create Company objects
    vector<Company> companies = {
        {"Tata", 5000000, 1000},
        {"Mahindra", 60000000, 3000},
        {"Adani", 70000000, 2000}
    };
    // Create Fetch_User_Data object and set user data
    Fetch_User_Data user;

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
    userID = user.generateUserID();
    user.setUserData(userName, password, age, deposit, userID);

    //Display company info
    for (const auto& company : companies) {
        company.displayShareInfo();
    }
      

    int companyIndex = -1;

    while (true) {
        if (companyIndex == -1) {
            cout << "\nEnter the company index (0 to " << companies.size() - 1 << "): \n";
            for (size_t i = 0; i < companies.size(); ++i) {
                cout << "Index " << i << ": " << companies[i].name << endl;
            }
            cin >> companyIndex;

            if (companyIndex < 0 || companyIndex >= companies.size()) {
                cout << "Invalid company index. Try again." << endl;
                companyIndex = -1;
                continue;
            }
        }

        cout << "Options: \n1. Buy\n2. Sell\n3. Display Share Info\n4. Display All Companies' Share Prices"
                "\n5. Withdraw, Deposit or Show Account Balance\n-1. Change Company\n0. Exit" << endl;
        int option;
        cin >> option;

        if (option == 0) {
            break;
        }
        // Switches between options for buy and sell
        switch (option) {
            case 1:
                cout << "Enter the quantity to buy: ";
                double quantityToBuy;
                cin >> quantityToBuy;
                companies[companyIndex].buy_share(quantityToBuy, transaction);
                break;

            case 2:
                cout << "Enter the quantity to sell: ";
                double quantityToSell;
                cin >> quantityToSell;
                companies[companyIndex].sell_share(quantityToSell, transaction);
                break;

            case 3:
                companies[companyIndex].displayShareInfo();
                break;

            case 4:
                for (const auto& company : companies) {
                    cout << "Company: " << company.name << endl;
                    cout << "Current Share Prices:" << endl;

                    const vector<double>& sharePrices = company.getSharePrices();
                    for (size_t i = 0; i < sharePrices.size(); ++i) {
                        cout << "Time Unit " << i + 1 << ": " << sharePrices[i] << endl;
                    }

                    cout << endl;
                }
                break;

            case 5:
                int option1;
                double amount;
                cout << "Options: \n1. Withdraw\n2. Deposit\n3. Show Account Balance"<< endl;
                cin >> option1;
                if(option1==1 || option1==2){
                    cout << "Enter the amount: ";
                    cin >> amount;
                    transaction.saveTransaction(option1, amount);
                } else if(option1==3){
                    transaction.displayTransactionHistory();
                } else
                    cout << "Invalid option!";

            case -1:
                companyIndex = -1;
                break;

            default:
                cout << "Invalid option. Try again." << endl;
        }

        // Analyze share prices for the selected company when the analysis vector reaches 6 elements
        if (companyIndex != -1) {
            const vector<double>& sharePrices = companies[companyIndex].getSharePrices();
            analysis = checkSharePrice(sharePrices);

            if (analysis.size() == 5) {
                cout << "Analysis of Share Prices:" << endl;
                for (size_t i = 0; i < analysis.size(); ++i) {
                    cout << "Time Unit " << i + 1 << ": " << analysis[i] << endl;
                }

                  if (analysis[0] >= 50 && analysis[1] >= 50 && analysis[2] >= 50 &&
                    analysis[3] == 0 && analysis[4] == 0) {
                    cout << "Bearish Engulfing Pattern: Price would likely decline" << endl;    // Demo case mentioned in sample Input and output
                } else if (analysis[0] <= -50 && analysis[1] <= -50 && analysis[2] <= -50 &&
                           analysis[3] == 0 && analysis[4] == 0) {
                    cout << "Bullish Engulfing Pattern: Price would likely increase" << endl;
                } else if (analysis[0] >= 50 && analysis[1] >= 50 && analysis[2] <= -150) {
                    cout << "Bearish Evening Star: Sellers are taking control, likely to stay "
                            "lower for longer" << endl;
                } else if (analysis[0] >= 50 && analysis[1] >= 50 && analysis[2] >= 50 &&
                           analysis[3] == -50) {
                    cout << "Bearish Harami: Price will likely go up, not much to worry about "
                            "but keep an eye on it." << endl;
                } else if (analysis[0] <= -100 && analysis[1] <= -100 && analysis[2] <= -200 &&
                           analysis[3] >= 50) {
                    cout << "Bullish harami: Price will likely go down, not much to worry about "
                            "but keep an eye on it. " << endl;
                } else {
                    cout << "No Analysis Called, God is great, but money isnt" << endl;
                }

                analysis.clear(); // Clear the analysis vector after performing analysis
            }
        }
    }

    return 0;
}