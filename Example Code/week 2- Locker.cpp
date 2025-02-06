/* test locker passwords*/
#include <iostream> 
using namespace std;

class Locker {

public:
    Locker(int pass) {
        this->id = ++objectCount;
        this->pass = pass;
        cout << "Locker number  -> " 
            << objectCount << " is created!\n";
    }
    ~Locker() {
        cout << "Locker number -> " << objectCount << " destructed!\n";
        objectCount--;
    }
    int getPass() { return pass; }
    int getID() { return id; }

    static int objectCount;  //static 
private:
    int id, pass;
};

int Locker::objectCount = 0; //starter value for static mem

int main() {
    //create locker objects
    
    int pass = 10000 + rand() % 10000;
    Locker L1(pass); //populate objects with passwords
    pass = 10000 + rand() % 10000;
    Locker L2(pass);

    cout << "Password for locker # " << L1.getID() << " is " << L1.getPass() << endl;
    cout << "Password for locker # " << L2.getID() << " is " << L2.getPass() << endl;

    /*for (int i = 1; i <= 100; ++i) {
        
    }*/
    cout << "Total locker count: " << Locker::objectCount << endl;
    return 0;
}