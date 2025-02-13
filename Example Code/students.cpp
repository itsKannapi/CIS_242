#include <iostream>
#include "Students.h"
using namespace std;
int main() {
    Student s("Dummy");
    s.setName("James");
    cout << s.getName() << endl;
    return 0;
}
