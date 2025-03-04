#include<iostream>
#include<string> //getline
#include<iomanip> //setprecision
using namespace std;
int main(int argc , char **argv ) {
    if (argc > 0) {
        cout << "Entered true value 1 " << argv[1] << endl;
        cout << "Total arguments given " << argc << endl;
    }
    string data;
    double number;
    cout << "Enter a string of characters \n";
    getline(cin, data);
    cout << "Enter a numeric value \n";
    cin >> number;
    //cout.precision(2);
    cout << data;
    cout.width(10);
    cout<<setprecision(1)<< fixed<<number;
}