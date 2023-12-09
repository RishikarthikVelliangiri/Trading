// Fetch_User_Data.cpp
#include "Fetch_User_Data.hpp"

void Fetch_User_Data::setUserData(const string& name, const string& pass, const string& userAge, double deposit, const string& userID) {
    names.push_back(name);
    passwords.push_back(pass);
    ages.push_back(userAge);
    amounts.push_back(deposit);
    // Generate and store a user ID when setting user data
    userIDs.push_back(generateUserID());
}

const vector<string>& Fetch_User_Data::getNames() const {
    return names;
}

const vector<string>& Fetch_User_Data::getPasswords() const {
    return passwords;
}

const vector<string>& Fetch_User_Data::getAges() const {
    return ages;
}

const vector<double>& Fetch_User_Data::getAmounts() const {
    return amounts;
}

const vector<string>& Fetch_User_Data::getUserIDs() const {
    return userIDs;
}

string Fetch_User_Data::generateUserID() {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    const int length = 10;

    string userID;
    userID.reserve(length);

    // Randomly select characters from the 'chars' string to create the user ID
    for (int i = 0; i < length; ++i) {
        int index = rand() % chars.length();
        userID.push_back(chars[index]);
    }

    return userID;
}
