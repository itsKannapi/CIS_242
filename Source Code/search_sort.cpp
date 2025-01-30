/* write data to a file 
#include<iostream>
#include<fstream>

using namespace std;

int main() {

	ofstream fout("data.txt");

	for (int i = 0; i < 20; ++i)

		fout << i << endl;

	fout.close();

	return 0;
}
*/
#include<iostream>
#include<fstream>
/* read data from a file */
using namespace std;
void populate(int arr[], int size, string filename) {
	ifstream fin(filename);
	for (int i = 0; i < size; ++i) fin >> arr[i];
	fin.close();
}
void print(int arr[], int size) {
	for (int i = 0; i < size; ++i) cout << arr[i] << endl;
}
void sort(int arr[], int size) { 
	//compare each element 
	for (int i = 0; i < size - 1; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int linearSearch(int arr[], int size, int key) {
	//search from start
	for (int i = 0; i < size; ++i) 
		if (arr[i] == key) {
			cout << "Search acquired at position " << arr[i] << endl;
			return 1;
		}
	return -1;
}
void binarySearch(int arr[], int size, int key) {
	//cut list in half
}
int main() {
	const int size = 20;
	int a[size];
	populate(a, size, "data.txt");
	if (linearSearch(a, size, 6) != -1)
		cout << "Search unfound " << endl;
	if (linearSearch(a, size, 26) != -1)
		cout << "Search unfound " << endl;
	sort(a, size);
	print(a, size);
	
	return 0;
}