// Fetch_User_Data.hpp
#ifndef FETCH_USER_DATA_HPP
#define FETCH_USER_DATA_HPP

#include "include_statements.hpp"

class Fetch_User_Data {
private:
    vector<string> names;
    vector<string> passwords;
    vector<int> ages;
    vector<double> amounts;
    vector<string> userIDs;  // New vector to store user IDs

public:
    void setUserData(const string& name, const string& pass, int userAge, double deposit);

    // Getter methods to retrieve information
    const vector<string>& getNames() const;
    const vector<string>& getPasswords() const;
    const vector<int>& getAges() const;
    const vector<double>& getAmounts() const;
    const vector<string>& getUserIDs() const;  // Getter for user IDs

    // Function to generate a 10-digit user ID
    string generateUserID();
};

#endif
