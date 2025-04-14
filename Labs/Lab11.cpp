#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int bs(int a[], int size, int key)
{
    int l = 0, r = size - 1, mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        if (key == a[mid]) {
            return mid;
        }

        cout << "\nl r mid a[mid] \n" << l << " " << r << " " << mid << " " << a[mid] << "\n";

        if (key < a[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int response;
    const int size = 25;
    int a[size];
    int item, location;

    ifstream fin("numbers.txt");

    if (!fin) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int index = 0;
    while (index < size && fin >> a[index]) {
        index++;
    }

    fin.close();
    sort(a, a + index);

    do {
        cout << "Enter the item you are searching for: ";
        cin >> item;
        location = bs(a, index, item);
        if (location > -1) {
            cout << "Item found at index: " << location << endl;
        }
        else {
            cout << "Item not found." << endl;
        }
        cout << "Do you wish to continue? Enter 1 for yes, 0 to quit: ";
        cin >> response;
    } while (response == 1);

    return 0;
}
