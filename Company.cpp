#include "Company.hpp"

SharePriceHistory::SharePriceHistory(){}

Company::Company(const string& n, double value, double share)
    : name(n), total_value(value), total_share(share),
      initial_share_price(total_value / total_share),
      current_share_price(initial_share_price) {}

void Company::buy_share(double buy_quantity, Transaction& transaction) {
    double buy_amount = buy_quantity * current_share_price;

    // Check if the user has enough funds to buy the shares
    if (buy_amount > transaction.getCurrentBalance()) {
        cout << "Insufficient funds to buy " << buy_quantity << " shares of " << name << "." << endl;
        return;
    }else{
    total_share -= buy_quantity;
    current_share_price = total_value / total_share;
    SharePriceHistory::addSharePrice(current_share_price);
    user_shares[name] += buy_quantity;
    transaction.saveTransaction(1, buy_amount);

    cout << "Bought " << buy_quantity << " shares of " << name << ". New price of share: " << current_share_price << endl;
    }
}

void Company::sell_share(double sell_quantity, Transaction& transaction) {
    if (user_shares[name] < sell_quantity) {
        cout << "Not enough shares of " << name << " to sell." << endl;
        return;
    }else{

    double sell_amount = sell_quantity * current_share_price;
    total_share += sell_quantity;
    current_share_price = total_value / total_share;
    SharePriceHistory::addSharePrice(current_share_price);
    user_shares[name] -= sell_quantity;
    transaction.saveTransaction(2, sell_amount);

    cout << "Sold " << sell_quantity << " shares of " << name << ". New price of share: " << current_share_price << endl;
    }
}

void Company::displayShareInfo() const {
    cout << "\nCompany: " << name << ", \nTotal Shares: " << total_share << ", \nCurrent Share Price: " << current_share_price << endl;
    SharePriceHistory::displaySharePriceHistory();
}

double Company::get_current_share_price() const {
    cout << "Current share price of " << name << " is " << current_share_price << endl;
    return current_share_price;
}

// Recursive function for analyzing share prices
void Company::checkSharePriceRecursive(const vector<double> &v, vector<double> &differences, size_t index) {
    if (index >= v.size() - 1) {
        return;
    }
    double diff = v[index + 1] - v[index];
    differences.push_back(diff);

    checkSharePriceRecursive(v, differences, index + 1);
}

// Function to check share prices
vector<double> checkSharePrice(const vector<double> &v) {
    Company Company("Example Company", 100.0, 20.0);
    vector<double> differences;
    Company.checkSharePriceRecursive(v, differences, 0);
    return differences;
}
