#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class Account {
    // public:
    //         float fAmount;
    //         char cType;
    //         char stDescription[0];
    //         float fBalance;
};
float fAmount;
char cType;
char stDescription[0];
float fBalance;

void Calculate();
void ObtainData();
void PrintReport();

int main() {
    ObtainData();
}
void Calculate(){
    // statements for the Account class function Calculate()
    if (cType == 'd' || cType == 'D'){
        strcpy(stDescription, "Deposit");
        fBalance += fAmount;
    }
    else if (cType == 'w' || cType == 'W'){
        strcpy(stDescription, "Withdrawal");
        fBalance -= fAmount;
    }
    else {
        strcpy(stDescription, "Invalid");
        cout << "Invalid Transaction Type" << endl;
    }
}
void ObtainData(){
    cout << "What is your transaction type? (D/d for Desposit, W/w for Withdrawl): ";
    cin >> cType;
    if (cType == 'd' || cType == 'D'){
        cout << "Insert Amount to Deposit: ";
    }
    else if (cType == 'w' || cType == 'W'){
        cout << "Insert Amount to Withdrawl: ";
    }
    else {
        strcpy(stDescription, "Invalid");
        cout << "Invalid Transaction Type" << endl;
    }
} //To prompt and input transaction type and amount
    
void PrintReport(){

 } //To generate a formatted report