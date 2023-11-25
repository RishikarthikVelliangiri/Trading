// Fetch_User_Data.h
#ifndef FETCH_USER_DATA_H
#define FETCH_USER_DATA_H

#include "include_statements.hpp"

class Fetch_User_Data {
private:
    vector<string> names;
    vector<string> passwords;
    vector<int> ages;
    vector<double> amounts;

public:
    void setUserData(const string& name, const string& pass, int userAge, double deposit);

    // Getter methods to retrieve information
    const vector<string>& getNames() const;
    const vector<string>& getPasswords() const;
    const vector<int>& getAges() const;
    const vector<double>& getAmounts() const;
};

#endif
