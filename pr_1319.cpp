#include <iostream>
#include <vector>
//in progress
using namespace std;

int offset(int x, int y, int n)
{
	return y*n + x;
}

void set(vector<int>& v, int x, int y, int n, int value)
{
	v.at(offset(x,y,n)) = value;
}

int get(const vector<int>& v, int x, int y, int n)
{
	return v.at(offset(x,y,n));
}


int main()
{
	int n;
	cin >> n;
	vector<int> v(n*n);

	// create rotates coordinates system
	const int X = (n - 1) * 2 + 1;

	int yfrom = 0, yupto = 0;
	int yfrom_delta = 1;
	int yupto_delta = -1;
	const int CENTER = n - 1;

	for(x = 0; x < X; ++x) {
		for(y = yfrom; y >= yupto; --y) {
			int xn = (n - 1) - x
		}

		if(x == CENTER) {
			yfrom_delta = -yfrom_delta;
			yupto_delta = -yupto_delta;
		}
		yfrom += yfrom_delta;
		yupto += yupto_delta;
	}


	// output square
	for(int y = 0; y < n; ++y)
	{
		for(int x = 0; x < n; ++x) {
			if(x != 0) cout << ' ';
			cout << get(v,x,y,n);
		}
		cout << '\n';
	}

	return 0;
}
