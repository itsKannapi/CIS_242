// class BankAccount
// this is the abstract base class for all types of bank accounts
using namespace std;
#include <iostream>;
#include <fstream>;

class BankAccount{
    public:
        BankAccount(int = 0, float = 0);
        void deposit(float amount) {
            bal += amount;
            log_transaction("Deposit", amount);
        }
        int account_num() const {
            return acctnum;
        }
        float balance() const {
            return bal;
        }
        virtual void print() = 0; //  virtual function
    protected :
        int acctnum;
        float bal;
        void log_transaction(const string& type, float amount) {
            ofstream file("accounts.dat", ios::app);
            if (file.is_open()) {
                file << "Account #: " << acctnum << ", " << type << ": $" << amount << ", New Balance: $" << bal << endl;
                file.close();
            }
            else {
            cerr << "Error: Unable to open file for writing!" << endl;
            }
        }
};
class CheckingAccount : public BankAccount{
    public:
        CheckingAccount(int num, float ibal) : BankAccount(num, ibal) {}

        void withdraw(float amount) {
            if (bal - amount >= 0) {
                bal -= amount;
                if (bal < 1000) {
                bal -= 0.50;
                }
                log_transaction("Withdrawal", amount);
            }
            else {
            cout << "Insufficient funds for withdrawal!" << endl;
            }
        }
        void print() override {
            cout << "Checking Account - Account #: " << acctnum << " Balance: $" << bal << std::endl;
        }
};

class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(int num, float ibal) : BankAccount(num, ibal) {}

    void withdraw(float amount) {
        if (bal - amount >= 0) {
            bal -= amount;
            log_transaction("Withdrawal", amount);
        } else {
            std::cout << "Insufficient funds for withdrawal!" << std::endl;
        }
    }

    void print() override {
        std::cout << "Savings Account - Account #: " << acctnum << " Balance: $" << bal << std::endl;
    }
};

// constructor for BankAccounts; both args can default to zero
BankAccount :: BankAccount(int num, float ibal){
    acctnum = num;
    bal = ibal;
}

int main() {
    CheckingAccount checker(17381, 1500.00);
    SavingsAccount saver(68490, 500.00);

    // deposits and withdrawals
    checker.deposit(200.00);
    checker.withdraw(800.00);
    saver.deposit(100.00);
    saver.withdraw(600.00);

    // array of base class pointers
    BankAccount* accounts[2];
    accounts[0] = &checker;
    accounts[1] = &saver;

    // Print account information via base class pointer
    for (int i = 0; i < 2; i++) {
        accounts[i]->print();
    }

    return 0;
}