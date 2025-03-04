#include<iostream>
#include<iomanip> //setw, fixed, precision
#include<fstream>
#include<vector>
#include<locale> // comma seperator, currency locale

using namespace std;

int main() {

double balance;
char trans_type = '\0';
string id;
vector<double> vecBal;
fstream file;

locale loc("en_US.UTF-8");
cout.imbue(loc);
cout << setprecision(2);  // set formatting

file.open("data.dat", ios::app);  // open file for writing
file << fixed << setprecision(2);  // set formatting
cout<<"Please enter id, amount, type - Ctrl ^ C to quit\n";
while (cin>>id>>balance>>trans_type) {

file << id << " " << balance << " " << trans_type << endl;

}
file.close();

// reopen for reading
file.open("data.dat");

cout << "id\tbalance\ttransaction type\n"; // heading
while (file >> id >> balance >> trans_type) {
// make sure balance headings with details (nice columnar justification)
// make use of setfill
cout << id << "\t" << setiosflags(ios::fixed | ios::internal) << balance << "\t" << trans_type << endl;
vecBal.push_back(balance);
}
    // display queries
// 1. total balances
// 2. Total withdraws (check type)
// 3. Total deposit (check type)
// 4. Check individual totals by an id
double totalBal = 0;
for (int i = 0; i < vecBal.size(); ++i)
totalBal += vecBal[i];

cout << "Total balances -> " << totalBal<< endl;


}