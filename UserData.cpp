#include "include_statements.h"

class Fetch_User_Data {
private:
    string userName, password;
    int age;
    double amount;

public:
    void getUserName(const std::string& name) {
        this->userName = name;
    }

    void getPassword(const std::string& pass) {
        this->password = pass;
    }

    void getAge(int userAge) {
        this->age = userAge;
    }

    void getAmount(double amount){
        this->amount = amount;
    }

    // Getter methods to retrieve information
    const string& getUserName() const {
        return userName;
    }

    const string& getPassword() const {
        return password;
    }

    int getAge() const {
        return age;
    }

    double getAmount() {
        return amount;
    }
};

int main() {
    Fetch_User_Data user;
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

    user.getUserName(userName);
    user.getPassword(password);
    user.getAge(age);
    user.getAmount(deposit);

    vector<string> names;
    vector<string> passwords;
    vector<int> ages;
    vector<double> amounts;

    names.push_back(user.getUserName());
    passwords.push_back(user.getPassword());
    ages.push_back(user.getAge());
    amounts.push_back(user.getAmount());

    return 0;
}
