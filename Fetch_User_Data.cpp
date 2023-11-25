// Fetch_User_Data.cpp
#include "Fetch_User_Data.hpp"

void Fetch_User_Data::setUserData(const string& name, const string& pass, int userAge, double deposit) {
    names.push_back(name);
    passwords.push_back(pass);
    ages.push_back(userAge);
    amounts.push_back(deposit);
}

const vector<string>& Fetch_User_Data::getNames() const {
    return names;
}

const vector<string>& Fetch_User_Data::getPasswords() const {
    return passwords;
}

const vector<int>& Fetch_User_Data::getAges() const {
    return ages;
}

const vector<double>& Fetch_User_Data::getAmounts() const {
    return amounts;
}


