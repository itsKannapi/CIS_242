//
// Created by Joey Tamondong on 3/17/25.
//

#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

void searchStudent(map<string, string>& wMap, const string& key) {
    auto it = wMap.find(key);
    if (it != wMap.end()) {
        cout << "Search result => " << it->second << endl;
    }
    else {
        cout << "Student with last name '" << key << "' not found." << endl;
    }
}
void removeStudent(map<string, string>& wMap, const string& key) {
    if (wMap.erase(key)) {
        cout << "Student with last name '" << key << "' removed successfully." << endl;
}
    else {
        cout << "Student with last name '" << key << "' not found." << endl;
    }
}

void updateStudent(map<string, string>& wMap, const string& key, const string& newVal) {
    auto it = wMap.find(key);
    if (it != wMap.end()) {
        it->second = newVal;
        cout << "Student with last name '" << key << "' updated to first name '" << newVal << "'." << endl;
    }
    else {
        cout << "Student with last name '" << key << "' not found." << endl;
    }
}

void getStudentCount(const map<string, string>& wMap) {
    cout << "Total number of students: " << wMap.size() << endl;
}

void printAllStudents(const map<string, string>& wMap) {
    for (const auto& entry : wMap) {
        cout << entry.second << " " << entry.first << endl;
    }
}

int main() {
    ifstream ifp("names.txt");
    map<string, string> wMap;

    string key, val;

    while (ifp >> key >> val) {
        wMap.insert(make_pair(key, val));
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Search Student for first name (by last name)\n";
        cout << "2. Remove Student (by last name)\n";
        cout << "3. Update Student (change first name by last name)\n";
        cout << "4. Get Student count\n";
        cout << "5. Print all Students (First name first, Last name second)\n";
        cout << "6. Exit application\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 6." << endl;
            continue;
        }

        if (choice == 1) {
            cout << "Enter last name to search: ";
            cin >> key;
            searchStudent(wMap, key);
        }
        else if (choice == 2) {
            cout << "Enter last name to remove: ";
            cin >> key;
            removeStudent(wMap, key);
        }
        else if (choice == 3) {
            cout << "Enter last name to update: ";
            cin >> key;
            cout << "Enter new first name: ";
            cin >> val;
            updateStudent(wMap, key, val);
        }
        else if (choice == 4) {
            getStudentCount(wMap);
        }
        else if (choice == 5) {
            printAllStudents(wMap);
        }
        else if (choice == 6) {
            cout << "Good bye!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}


