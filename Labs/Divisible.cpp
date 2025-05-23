#include <iostream>
using namespace std;

class divisibleBy11 {
public:
    //declare two variables: input, hold
    int input, hold;
};

int main() {
    // (1) declare object of the class: d
    divisibleBy11 d;

    // (2) greet the user and request a number to test
    cout << "Enter a positive integer to check divisibility by 11: ";
    cin >> d.input;

    // (3) program reads user input and class object assigns value

    // (4) open a looping structure
    while (d.input > 99) {
        // (5) class object assigns hold variable to the modulus of d.input and 10
        d.hold = d.input % 10;

        // (6) class object assigns input variable to the quotient of d.input and 10
        d.input /= 10;

        // (7) the variable input is updated to the difference of d.input and d.hold
        d.input -= d.hold;
    }

    // (8) the variable hold is updated
    d.hold = d.input % 11;

    // (9) use if statement to test if d.hold is equal to 0
    if (d.hold == 0) {
        // (10) if the condition of the if statement is true display
        cout << "\nNumber is divisible by 11!" << endl;
    } else {
        // (11) otherwise display
        cout << "\nNumber is not divisible by 11." << endl;
    }

    return 0;
} //end main()