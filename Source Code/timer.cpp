#include <iostream>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	clock_t t;
	t = clock();

	size_t size = 100000;
	int s = 0;
	cout<<RAND_MAX<<endl;
	cin>>s;
	int *pInt = new int[s];
	for(size_t i = 0; i < s; i++) {
		pInt[i] = rand();
	    cout<<pInt[i]<<endl;
	}

	t = clock() - t;
	cout << "time: " << t << " miliseconds" << endl;
	cout << CLOCKS_PER_SEC << " clocks per second" << endl;
	cout << "time: " << t*1.0/CLOCKS_PER_SEC << " seconds" << endl;

	system("pause");
	delete [] pInt;
	return 0;
}