#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std; // programmer: Joey T
 int x, y;
 float profit;
void FindProfit(){
    if ((12 * x + 4 * y <= 156) && (7 * x + 3 * y <= 116)){
    cout << "the production schedule is feasible" << endl;
    profit = 3 * x + 1.5 * y;
    cout << "and the profit yielded by this schedule is $"
    << setiosflags(ios::fixed | ios::showpoint)
    << setprecision(2) << profit << endl;
    }
    else{
    cout << "\nproduction schedule is not feasible\n" << endl;
    }
    if(profit < 20){
        cout << "The profit margin is below $20!";
    }
}
int main(){
    char answer = 'y';
    cout << "Fruity Bakery" << endl;
    cout << "_ _ _ _ _ _ _\n\n" << endl;
    cout << "Apple Pies and Apple Tarts:\n" << endl;
    cout << "Production Scheduling Program:\n\n" << endl;
    cout << " the production constraints are:\n" << endl;
    cout << " 12x + 4y <= 156 Ounces of Fruit" << endl;
    cout << " 7x + 3y <= 116 Ounces of Dough" << endl;
    cout << "\n\n";
    cout << " where x equals the number of pies" << endl;
    cout << " and y equals the number of tarts\n" << endl;
    do{
    cout << "Please enter the number of pies" << endl;
    cin >> x;
    cout << "Please enter the number of tarts" << endl;
    cin >> y;
    FindProfit();
    cout << "\nEnter another production schedule?" << endl;
    cout << "type Y for Yes or N for No" << endl;
    cin >> answer;
    system("CLS");
    } while (answer == 'Y' || answer == 'y');
    return 0;
    }

