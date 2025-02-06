#include <iostream>
using namespace std;
int main() {
    int j = 2, * k = &j;
    *k = 3;
    cout << "J value= " << j << "\nK indirect value= " << *k << endl;
    cout << "J address= " << &j << "\nK pointer address= " << k << endl;
    j = 5;
    cout << "J value after= " << j << "\nK value after= " << *k << endl;
    cout << "J address= " << &j << "\nTrue K address= " << &k << endl;
    return 0;
}