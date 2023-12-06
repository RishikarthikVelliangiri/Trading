#ifndef COMPANY_HPP
#define COMPANY_HPP

#include "include_statements.hpp"
#include "Transaction.hpp"

class SharePriceHistory {
public:
    SharePriceHistory();
    vector<double> share_prices;

    void addSharePrice(double price) {
        share_prices.push_back(price);
    }

    void displaySharePriceHistory() const {
        cout << "Share Price History:" << endl;
        for (size_t i = 0; i < share_prices.size(); ++i) {
            cout << "Day " << i + 1 << ": " << share_prices[i] << endl;
        }
    }

    const vector<double>& getSharePrices() const {
        return share_prices;
    }
};

class Company : public SharePriceHistory {
public:
    string name;
    double total_value;
    double total_share;
    double initial_share_price;
    double current_share_price;
    unordered_map<string, double> user_shares;

    Company(const string& n, double value, double share);

    void buy_share(double buy_quantity, Transaction& transaction);
    void sell_share(double sell_quantity, Transaction& transaction);
    void displayShareInfo() const;
    double get_current_share_price() const;
    void checkSharePriceRecursive(const vector<double> &v, vector<double> &differences, size_t index);
};

#endif
