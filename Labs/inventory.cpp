#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class Inventory{
public:
    int local;
    int itemsNum[100];
    char itemsChar[100];
};
// global arrays / variables
int max1;
int letters[100];
int numbers[100];
double costs[100];
// function prototypes
void GenerateRandomLetters();
void GenerateRandomNumbers();
void GenerateRandomCosts();
int main()
{
// seed for the random number generator
srand(time(NULL));
GenerateRandomLetters();
GenerateRandomNumbers();
Inventory inv;
double totalCosts = 0;
int totalQty = 0;
for (int i = 0; i <= max1; i++){
inv.itemsNum[i] = numbers[i];
inv.itemsChar[i] = letters[i];

totalQty += numbers[i];
totalCosts += numbers[i] * costs[i];
}

cout << totalCosts / totalQty;
system("PAUSE");
return 0;
}
void GenerateRandomLetters()
{
char randChar = '\0';
int counter = 0;
int randNum = 0;
int maxLetters = 0;
cout << "How many items in the inventory?" << endl;
cin >> maxLetters;
for (counter = 0; counter < maxLetters; counter++)
{
// select a number between 0 and 25
randNum = 26 * (rand() / (RAND_MAX + 1.0));
// use ASCII code with 'a' = 97
// for lower case letters
randNum = randNum + 97;
// type cast to character
randChar = (char)randNum;
letters[counter] = randChar;
printf("Inventory Item: %c\n", randChar);
}
}
void GenerateRandomNumbers()
{
int counter = 0;
int maxNums = 0;
int randNum = 0;
cout << "How many numbers to simulate the inventory?" <<
endl;
cin >> maxNums;
max1 = maxNums;
for (counter = 0; counter < maxNums; counter++)
{
randNum = 100 * (rand() / (RAND_MAX + 1.0));
numbers[counter] = randNum;
printf("Item Quantity: %d\n", randNum);
}
}