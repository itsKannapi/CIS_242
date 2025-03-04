#include <iostream>
#include <fstream>
#include <string>
#include<functional>

using namespace std;

int main() {

	string mypassword = "jpapadem123", mypassword2 = "kp123";
	hash<string> hash_value;
	size_t hash;
	hash = hash_value(mypassword);
	
	fstream fout("hashwords.txt", ios::out);

	fout << hash << endl;
	cout << hash<<endl; 

    hash = hash_value(mypassword2);
	fout << hash << endl;
	cout << (hash);

	fout.close();

}

