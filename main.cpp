#include "include_statements.hpp"
#include "Fetch_User_Data.hpp"
#include "Transaction.hpp"
#include "Company.hpp"
#include "Transaction.cpp"
#include "Fetch_User_Data.cpp"
#include "Company.cpp"

int main() {
    string userName, password;
    int age;
    double deposit;

    vector<double> analysis;
// Create Company objects
    vector<Company> companies = {
        {"Tata", 5000000, 1000},
        {"Mahindra", 60000000, 3000},
        {"Adani", 70000000, 2000}
    };
    // Create Transaction object with the initial balance set to the deposit
    Transaction transaction(deposit);
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
    // Display starting balance
    cout << "Starting Balance: " << transaction.getCurrentBalance() << "\n\n";
    user.setUserData(userName, password, age, deposit);

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

        cout << "Options: Buy(1), Sell(2), Display Share Info(3), Display All Companies' Share Prices(4),"
                " Change Company(-1), Exit(0): ";
        int option;
        cin >> option;

        if (option == 0) {
            break;
        }

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

            if (analysis.size() == 6) {
                cout << "Analysis of Share Prices:" << endl;
                for (size_t i = 0; i < analysis.size(); ++i) {
                    cout << "Time Unit " << i + 1 << ": " << analysis[i] << endl;
                }

                // Perform analysis based on the conditions you provided
                if (analysis[1] - analysis[0] >= 2 && analysis[2] - analysis[1] >= 2 && analysis[3] - analysis[2] >= 2 &&
                    analysis[4] - analysis[3] == 0 && analysis[5] - analysis[4] == 0) {
                    cout << "Bearish Engulfing Pattern: Price would likely decline" << endl;
                } else if (analysis[1] - analysis[0] <= -2 && analysis[2] - analysis[1] <= -2 && analysis[3] - analysis[2] <= -2 &&
                           analysis[4] - analysis[3] == 0 && analysis[5] - analysis[4] == 0) {
                    cout << "Bullish Engulfing Pattern: Price would likely increase" << endl;
                } else if (analysis[1] - analysis[0] >= 2 && analysis[2] - analysis[1] >= 2 && analysis[3] - analysis[2] <= -4) {
                    cout << "Bearish Evening Star: Sellers are taking control, likely to stay "
                            "lower for longer" << endl;
                } else if (analysis[1] - analysis[0] >= 2 && analysis[2] - analysis[1] >= 2 && analysis[3] - analysis[2] >= 2 &&
                           analysis[4] - analysis[3] == -1) {
                    cout << "Bearish Harami: Price will likely go up, not much to worry about "
                            "but keep an eye on it." << endl;
                } else if (analysis[1] - analysis[0] <= -2 && analysis[2] - analysis[1] <= -2 && analysis[3] - analysis[2] <= -2 &&
                           analysis[4] - analysis[3] == 1) {
                    cout << "Bullish harami: Price will likely go down, not much to worry about "
                            "but keep an eye on it. " << endl;
                } else {
                    cout << "Blank Analysis (Test Case)" << endl;
                }

                analysis.clear(); // Clear the analysis vector after performing analysis
            }
        }
    }

    return 0;
}
