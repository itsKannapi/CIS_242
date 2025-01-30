#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main(){
    srand(time(NULL));
    double fMin = 20000.00, fMax = 0.00;
    double f = 0.00;
    double cost = 0.00;
    for (int i = 1; i <= 100; i++){
        f = (double)rand() / RAND_MAX;
        cost = ceil(fMin + f * (fMax - fMin)) / 100;
        cout << " cost = " << setprecision(2) << fixed << cost << endl;
    }
    cin.get();
return 0;
}