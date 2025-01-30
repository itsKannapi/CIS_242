#include<iostream>

using namespace std;

class Flip {
public:
	Flip(int id = 0) {  // default argument value contructor
		hCt = tCt = 0;
		this->id = id;
		cout << "\nObject is created - for game coin # is " << id << "\n";
	}
	~Flip() {
		cout<<"\nObject is destroyed - for game coin # is "<< id<<"\n";
	}
	int flip() {
		int random = rand() % 2;  // 0 or 1 outcome
		return random;
	}
private:
	int hCt, tCt;
	int id;
};

int main() {
   
	Flip f1(1), f2(2), f3;
	/*for (int i = 1; i <= 20; i++) {
		cout << "Flip for coin object #1 " << f1.flip()
			<< "\tFlip for coin object #2 " << f2.flip() <<endl;
		cout << ((i == 1) ? "\n" : "");
	}*/

}