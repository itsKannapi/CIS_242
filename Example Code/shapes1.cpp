#include<iostream>
using namespace std;

class shape {
private: 
	string name;
public:
	shape(string _name) { name = _name; }
	string getName() { return name; }
	shape() {}
};

class square : public shape {

private:
	int side;
public:
	square(int side) : shape("square")
	{
		this->side = side;
	}
	double getArea() { return side * side; }

};
int main() {
	shape myshape("Base shape");
	square mysquare(5);

	cout << "Shape name =>" << myshape.getName() << endl;
	cout << "Shape name =>" << mysquare.getName() << endl;

	shape shapes[5];

	shape* newshapes = &shapes[0];

	newshapes[0] = shape("base 2");
	newshapes[1] = square(10);
	newshapes[2] = square(20);
	newshapes[3] = square(30);

	for (int i = 0; i < 4; ++i) {
		cout << "Shape name =>" << newshapes[i].getName() << endl;
	}

}