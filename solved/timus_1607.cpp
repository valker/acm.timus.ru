//1607

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a,b,c,d;
//	a = 150; b = 50; c = 1000; d = 100;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	while(true) {
		a += b;
		if(a > c) { cout << c << endl; return 0; }

		c -= d;
		if(c < a) { cout << a << endl; return 0; }
	}
	return 0;
}

