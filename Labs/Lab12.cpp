#include <iostream>
#include <ctime>

//
// Created by Joey Tamondong on 4/15/25.
//
using namespace std;
// Set up globals
#define M 4 // Rows
#define N 4 // Cols

int path[M][N] = { 0 }; // To hold possible good cells upon visitation
int visits = 0; // Track cell visits
int treasure = 0;

// Function to print total treasure collected & number of cells visited
void print() {
	cout << "Total treasure obtained : " << treasure << endl;
	cout << "Total cells visited : " << visits << endl;
}

// Function to traverse the matrix recursively
void move_drone(int row, int col) {
	// Check if the current cell has been visited
	if (path[row][col] == 1) {

		cout << "Cell [" << row << "][" << col << "] has already been visited. Please choose another cell." << endl;
		cout << "Enter the next cell to visit (row col): ";
		cin >> row >> col;
		move_drone(row, col); // Recursively call move_drone with new coordinates
		return;
	}

	// Set array row/col to represent current cell has been visited
	path[row][col] = 1; // Set active cell
	visits++;
	cout << "Visited cell [" << row << "][" << col << "]" << endl;

	//If drone is destroyed

	if (row == 1 && col == 2) {
		cout << "Drone destroyed at cell. Game over!" << endl;
		print(); // Print total treasure and visits
		return;
	}

	// Collect treasure if a particular cell has been visited
	if (row == 0 && col == 1) {
		treasure += 10;
		cout << "Treasure Found " << endl;
	}

	if (row == 1 && col == 3) {
		treasure += 20;
		cout << "Treasure Found" << endl;
	}
	if (row == 2 && col == 2) {
		treasure += 30;
		cout << "Treasure Found" << endl;
	}

	if (row == 3 && col == 3) {
		treasure += 40;
		cout << "Bonus Treasure Found" << endl;
	}

	// If you found the secret tunnel
	if (row == 2 && col == 1) {
		char followTunnel;
		cout << "You've found a secret tunnel! Do you want to follow it? (Y/N): ";
		cin >> followTunnel;
		if (followTunnel == 'Y' || followTunnel == 'y') {
			row = 3;
			col = 0;
			cout << "Following the secret tunnel..." << endl;
			move_drone(row, col);
			return;
		}
	}

	//If missile is launched
	if (row == 3 && col == 0) {
		cout << "Mission accomplished!\n" << "You have launched the ice cream missile." << endl;
		print();
		return;
	}

	// Lose treasure if a particular cell has been visited
	if (row == 1 && col == 0) {
		treasure -= 5;
		cout << "Treasure lost" << endl;
	}

	// Ask user if they want to continue playing
	char choice;
	cout << "Do you want to continue playing? (Y/N): ";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		// Ask user for the next cell to visit
		cout << "Enter the next cell to visit (row col): " << endl;;
		cout << "Enter row" << endl;
		cin >> row;
		cout << "Enter Column" << endl;
		cin >> col;

		// Recursively call move_drone
		move_drone(row, col);
	}

	else {
		print(); // Print total treasure and visits
	}
}

int main() {
	srand(time(NULL)); // Seed random values

	// Output initial matrix coordinates
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cout << "a[" << i << "][" << j << "] ";
		}
		cout << endl;
	}

	// Ask user for the starting cell
	int start_row, start_col;
	cout << "Enter the starting cell to visit (row col): " << endl;
	cout << "Enter starting row" << endl;
	cin >> start_row;
	cout << "Enter starting Column" << endl;
	cin >> start_col;

	move_drone(start_row, start_col);

	return 0;
}	
