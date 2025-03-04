#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Function to read the first 5 lines of the file
void readFirst5Lines(fstream &file) {
    file.seekg(0, ios::beg); // Move to the beginning of the file
    string line;
    int lineCount = 0;
    
    cout << "\nFirst 5 lines:\n";
    while (getline(file, line) && lineCount < 5) {
        cout << "Line " << lineCount + 1 << ": " << line << endl;
        lineCount++;
    }
}

// Function to read the last 5 lines of the file
void readLast5Lines(fstream &file) {
    file.seekg(0, ios::end); // Move to the end of the file
    vector<string> lines;     // To store the last 5 lines
    string line;
    
    char ch;
    int lineCount = 0;
    bool newlineFound = false;

    while (file.tellg() > 0 && lineCount < 5) {
        file.seekg(-2, ios::cur); // Move back by one character
        
        file.get(ch); // Read the current character

        if (ch == '\n' || file.tellg() == 0) {  // If it's a newline or start of file
            if (!newlineFound) {
                lines.push_back(line);
                line.clear();
                newlineFound = true;
                lineCount++;
            }
        } else {
            line.insert(line.begin(), ch); // Insert character at the beginning of the line
            newlineFound = false; // Reset after getting a character
        }
    }

    // Print the last 5 lines (in reverse order since we read backwards)
    cout << "\nLast 5 lines:\n";
    for (int i = lines.size() - 1; i >= 0; i--) {
        cout << lines[i] << endl;
    }
}

// Function to write 10 lines to the file
void writeInitialLines(fstream &file) {
    file.seekp(0, ios::beg); // Move to the beginning of the file
    file << "Line 1: Hello, World!" << endl;
    file << "Line 2: This is a test file." << endl;
    file << "Line 3: Hello, World 2!" << endl;
    file << "Line 4: This is a test file 2." << endl;
    file << "Line 5: Hello, World 3!" << endl;
    file << "Line 6: This is a test file 3." << endl;
    file << "Line 7: Hello, World 4!" << endl;
    file << "Line 8: This is a test file 4." << endl;
    file << "Line 9: Hello, World 5!" << endl;
    file << "Line 10: This is the last test file." << endl;
}

int main() {
    fstream file("example.txt", ios::in | ios::out | ios::trunc);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Write 10 lines to the file initially
    writeInitialLines(file);

    // User choice for first or last 5 lines
    char choice;
    cout << "Do you want to read the first 5 lines or last 5 lines? (f/l): ";
    cin >> choice;

    if (choice == 'f' || choice == 'F') {
        // Read first 5 lines
        readFirst5Lines(file);
    } else if (choice == 'l' || choice == 'L') {
        // Read last 5 lines
        readLast5Lines(file);
    } else {
        cout << "Invalid choice!" << endl;
    }

    file.close();
    return 0;
}
