#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    float balance;        //account balance
    float amount;         //transaction amount
    char type;            //transaction type
    string description;   //transaction description

public:
    Account() : balance(0.0f) {} //initializing balance to 0

    void ObtainData() {
        cout << "Enter transaction type (D/d for Deposit, W/w for Withdrawal): \n";
        cin >> type;

        if (type == 'd' || type == 'D') {
            cout << "Enter amount to deposit: ";
            cin >> amount;
        }
        else if (type == 'w' || type == 'W') {
            cout << "Enter amount to withdraw: ";
            cin >> amount;
        }
        else {
            description = "Invalid";
            cout << "Invalid transaction type!" << endl;
        }
    }

    void Calculate() {
        const double interestRate = 0.02;
        if (type == 'd' || type == 'D') {
            description = "Deposit";
            balance += amount;
            balance += balance * interestRate;  // Add interest to the new balance
        }
        else if (type == 'w' || type == 'W') {
            if (amount > balance) {
                description = "Invalid";
                cout << "Insufficient funds for withdrawal!" << endl;
            } else {
                description = "Withdrawal";
                balance -= amount;
            }
        } 
        else {
            description = "Invalid";
        }
    }

    void PrintReport() {
        cout << "\nBanking Report";
        cout << "\n-----------------------";
        
        if (description == "Deposit") {
            cout << "\nTransaction Type: " << description;
            cout << "\nAmount: +$" << amount;
            cout << "\nNew Account Balance: $" << balance;
        }
        else if (description == "Withdrawal") {
            cout << "\nTransaction Type: " << description;
            cout << "\nAmount: -$" << amount;
            cout << "\nNew Account Balance: $" << balance;
        }
        else {
            cout << "\nInvalid transaction attempted!";
        }

        cout << "\n";
    }
};

int main() {
    Account myAccount;

    myAccount.ObtainData();
    myAccount.Calculate();
    myAccount.PrintReport();

    return 0;
}