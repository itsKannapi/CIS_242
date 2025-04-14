//
// Created by Joey Tamondong on 4/1/25.
//
#include <iostream>
#include <string>
using namespace std;
#define SIZE 5
int qu[SIZE], front = 0, rear = 0;

struct Servers {
	string name;
	int repNumber;
};

Servers reps[] = { {"Steve", 2}, {"Pete", 9}, {"Laura", 4}, {"Lance", 5}, {"Dawn", 7}};

int repCount = sizeof(reps) / sizeof(reps[0]);

int currentRepIndex = 0;

void enqueue();
void dequeue();
void display();

int main() {
	int ch;
	system("clear");
	while (1) {
		cout << "\n 1. add element";
		cout << "\n 2. remove element";
		cout << "\n 3. display queue";
		cout << "\n 4. exit application\n";
		cout << "\n enter your choice: ";
		cin >> ch;
		system("clear");
		switch (ch) {
		case 1:

			enqueue();

			break;
		case 2:

			dequeue();

			break;

		case 3:

			display();

			break;

		case 4:

			exit(0);

		default:
			cout << "\n invalid choice";
		}

	}

	system("PAUSE");
	return 0;

}


void enqueue() {

	int no = 0;

	if (rear == SIZE && front == 0)
		cout << "the queue is full";
	else {
		cout << "enter the num: ";
		cin >> no;
		qu[rear] = no;
		rear++;
	}
}


void dequeue() {
	int no, i;
	if (front == rear)
		cout << "the queue is empty";
	else {
		no = qu[front];
		front++;
		cout << "\n" << no << " is removed from the queue\n";
		Servers rep = reps[currentRepIndex];
		currentRepIndex = (currentRepIndex + 1) % repCount;
		cout << "Customer " << no << " is matched with " << rep.name << " #" << rep.repNumber << endl;
	}
}


void display() {

	int i, temp = front;
	if (front == rear)
		cout << "the queue is empty";
	else {
		cout << "\n element in the queue: ";
		for (i = temp; i < rear; i++) {
			cout << qu[i] << " ";
		}
	}
}
