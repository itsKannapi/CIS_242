#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

//Starter code
class FirstFit {
public:
    int cap;
    int itemsToPack[100];
    int binNumber;
    int totalBins;

    void pack(vector<int> vect, int num);
    void printBin();
};


class SecondFit {
public:
    int cap;
    int itemsToPack[100];
    int binNumber;
    int totalNumBins;

    void pack(vector<int> vect, int num);
    void printBin();

};

void FirstFit::pack(vector<int> vect, int num) {
    totalBins = 1;
    for (int i = 0; i < 100; i++) {
        itemsToPack[i] = 0;
    }
    binNumber = 0;
    char open = 'y';
    cout << "First Fit: " << endl;

    for (int i = 0; i < num; i++) {
        if (itemsToPack[binNumber] + vect[i] <= cap) {
            open = 'y';
            itemsToPack[binNumber] += vect[i];
            cout << "Bin " << binNumber + 1 << ": " << itemsToPack[binNumber] << endl;
        }
        else{
            open = 'n';
        }
        if (open == 'n') {
            binNumber++;
            totalBins++;
            itemsToPack[binNumber] += vect[i];
            cout << "Bin " << binNumber + 1 << ": " << itemsToPack[binNumber] << endl;
        }

        open = 'y';
    }
}

void FirstFit::printBin() {
    cout << "---------------------------------------------------" << endl;
    cout << "Value for each bin:" << endl;
    for (int i = 0; i < totalBins; ++i) {
        cout << itemsToPack[i] << " ";
    }
    cout << endl;
    cout << "Total number of bins used for One is " << totalBins << endl;
    cout << "---------------------------------------------------" << endl;
}

void SecondFit::pack(vector<int> vect, int num) {
    totalNumBins = 1;
    for (int i = 0; i < 100; i++) {
        itemsToPack[i] = 0;
    }
    binNumber = 0;
    char open = 'y';

    cout << "Next Fit: " << endl;
    for (int i = 0; i < num; i++) {
        if (itemsToPack[binNumber] + vect[i] <= cap) {
            open = 'y';
            itemsToPack[binNumber] += vect[i];
            cout << "Bin " << binNumber + 1 << ": " << itemsToPack[binNumber] << endl;
        }
        else {
            binNumber++;
            totalNumBins++;
            itemsToPack[binNumber] += vect[i];
            cout << "Bin " << binNumber + 1 << ": " << itemsToPack[binNumber] << endl;
    }
    open = 'y';
}

}
void SecondFit::printBin() {
    cout << "---------------------------------------------------" << endl;
    cout << "Value for each bin:" << endl;

    for (int i = 0; i < totalNumBins; ++i) {
        cout << itemsToPack[i] << " ";
    }
    cout << endl;
    cout << "The total number of bins used for Two is " << totalNumBins << endl;
    cout << "---------------------------------------------------" << endl;

}

void print(const vector<int>&);
int getRandomValue(int val);
int main() {

    vector<int> vect;
    int pos = 0;
    int num = 0;
    int count = 1;
    int upperBound = 0;

    srand(time(NULL));

    cout << "How many items are to be packed? ";
    cin >> num;
    cout << "What is the bin capacity? ";
    cin >> upperBound;

    while (count <= num) {
        pos = getRandomValue(upperBound);
        vect.push_back(pos);
        count++;
}

    cout << "-----------------------------" << endl;

    cout << "\nitems to pack: \n";

    print(vect);

    FirstFit pack1;
    pack1.cap = upperBound;
    pack1.pack(vect, count - 1);
    pack1.printBin();

    SecondFit pack2;
    pack2.cap = upperBound;
    pack2.pack(vect, count - 1);
    pack2.printBin();

    system("PAUSE");
    return 0;
}

//Starter code
int getRandomValue(int ub) {
    int element = 0;
    int upperBound = ub;
    int lowerBound = 1;
    element = rand() % upperBound + lowerBound;
    return element;
}

//Starter code
void print(const vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "-----------------------------" << endl;
}