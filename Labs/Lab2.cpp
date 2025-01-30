#include <iostream>
#include <cstdlib>    
#include <iomanip>    
using namespace std;
 
/*
   Programer: Joey Tamondong
*/
 
void DisplayInfo()
{
    cout << "Epic Electronics" << endl;
    cout << "----------------------" << endl;
    cout << "Standard Desktop, Laptop and Portable Palm Models:" << endl;
    cout << "\nProduction Scheduling program:\n" << endl;
    cout << " The production constraints are:" << endl;
    cout << "  40d + 30l + 20p <= 2460   (Labor Constraints in hours)" << endl;
    cout << "  550d + 225l + 175p <= 50000   (Capital Constraints in USD)\n" << endl;
    cout << " where: d = number of Standard Desktop Models" << endl;
    cout << "        l = number of Laptop Models" << endl;
    cout << "        p = number of Portable Palm Models" << endl;
    cout << endl;
}
 
void FindProfit(int d, int l, int p)
{
    // Check labor and capital constraints
    bool feasible = ((40 * d + 30 * l + 20 * p) <= 2460) &&
        ((550 * d + 225 * l + 175 * p) <= 50000);
 
    if (feasible){
        cout << "The production schedule is feasible." << endl;
        double profit = 1.30 * (550 * d + 225 * l + 175 * p);
        cout << "And the profit yielded by this schedule is $" << fixed << setprecision(2) << profit << endl;
    }
    else
    {
        cout << "\nThe production schedule is NOT feasible.\n" << endl;
    }
}
 
int main()
{
    int d = 0;   // number of desktop models
    int l = 0;   // number of laptop models
    int p = 0;   // number of palm models
    char answer = 'Y';
 
    do
    {
     system("clear");
 
        DisplayInfo();
 
        cout << "Please enter the number of Standard Desktop Models: ";
        cin >> d;
        cout << "Please enter the number of Laptop Models: ";
        cin >> l;
        cout << "Please enter the number of Portable Palm Models: ";
        cin >> p;
 
        // Compute feasibility and profit
        FindProfit(d, l, p);
 
        // Prompt for another run
        cout << "\nEnter another production schedule? (Y/N): ";
        cin >> answer;
 
    } while (answer == 'Y' || answer == 'y');
 
    return 0;
}