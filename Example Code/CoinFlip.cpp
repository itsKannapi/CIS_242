#include<iostream>

using namespace std;

class Flip{

    public:
        Flip(int _id = 0){
            id = _id;
            //object constructor
            cout << "object created for id " << id << endl;
        }
        ~Flip(){
            //object destructor
            cout << "object is destroyed for id " << id << endl;
        }
        int flip(){
            return rand() % 2;
        }
    private: 
        int hct,tct;
        int id;
};

int main(){
    Flip flip1(1), flip2(2);

    srand(time(NULL)); //send random number)
    //time to flip coins
    for (int i = 0; i < 20; i++){
        cout << "Flip coin1 " << flip1.flip() << endl;
        cout << "Flip coin2 " << flip2.flip() << endl;
    }
}