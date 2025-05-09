//
// Created by Joey Tamondong on 4/21/25.
//
#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

void findMaxNode(int arr[], int size) {
    if (size == 0) {
        cout << "The tree is empty.\n";
        return;
    }
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    cout << "The maximum node value is: " << max << endl;
    cout << endl;
}

// Function to print all node values in the array
void printNodes(int arr[], int size) {
    cout << "Node value(s): \n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Function to insert a node at a specific index
void insertNode(int arr[], int& size) {
    if (size >= MAX_SIZE) {
        cout << "Cannot add more nodes. The tree is full.\n";
        return;
    }

    int indexToInsert;
    cout << "Where would you like to insert a node? (1-based index): ";
    cin >> indexToInsert;
    indexToInsert -= 1; // Convert to zero-based index

    if (indexToInsert < 0 || indexToInsert > size) {
        cout << "Invalid index. Please try again.\n";
        return;
    }

    int value;
    cout << "Enter the value of the new node: ";
    cin >> value;

    for (int i = size; i > indexToInsert; i--) {
        arr[i] = arr[i - 1];
    }
    arr[indexToInsert] = value;
    size++;

    cout << "Node added successfully.\n";
    printNodes(arr, size);
}

// Function to delete a node at a specific index
void deleteNode(int arr[], int& size) {
    if (size == 0) {
        cout << "The tree is empty. Nothing to delete.\n";
        return;
    }

    int indexToDelete;
    cout << "Enter the index of the node to delete (1-based index): ";
    cin >> indexToDelete;
    indexToDelete -= 1; // Convert to zero-based index

    if (indexToDelete < 0 || indexToDelete >= size) {
        cout << "Invalid index. Please try again.\n";
        return;
    }

    for (int i = indexToDelete; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;

    cout << "Node deleted successfully.\n";
    printNodes(arr, size);
}

// Main function
int main() {
    // Unmodified starter code setup
    int nodeVals[] = { 2, 7, 5, 2, 6, 9, 5, 11, 4 };
    int levels[] = { 1, 2, 3, 4 };
    char pointLR[] = { 'L', 'R', 'L', 'R', 'N', 'R', 'N', 'N', 'L', 'R', 'L', 'N', 'N', 'N', 'N', 'N', 'N', 'N' };

    int root = nodeVals[0];
    const int SIZE = sizeof(levels) / sizeof(levels[0]);
    int height = SIZE - 1;
    int treeSize = sizeof(nodeVals) / sizeof(nodeVals[0]);

    cout << "Size of binary tree: " << treeSize << endl;
    cout << "Height of binary tree: " << height << endl;
    cout << "Value of root node: " << root << endl;

    // Menu for operations
    int choice;
    do {
        cout << "\nBinary Tree Operations Menu:\n";
        cout << "1. Print all nodes\n";
        cout << "2. Find maximum node\n";
        cout << "3. Insert a node\n";
        cout << "4. Delete a node\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printNodes(nodeVals, treeSize);
            break;
        case 2:
            findMaxNode(nodeVals, treeSize);
            break;
        case 3:
            insertNode(nodeVals, treeSize);
            break;
        case 4:
            deleteNode(nodeVals, treeSize);
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 5);

    return 0;
}