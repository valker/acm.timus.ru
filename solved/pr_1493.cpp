#include <iostream>
//ac
using namespace std;

int get_last_num(int n)
{
	return n % 10;
}

bool last_nine(int n)
{
	return get_last_num(n) == 9;
}

int calc(int v)
{
	int s = 0;
	s += v % 10;
	s += (v % 100) / 10;
	s += (v % 1000) / 100;
	return s;
}

int first(int n) {
	int v = n / 1000;
	return calc(v);
}

int last(int n) {
	int v = n % 1000;
	return calc(v);
}

bool last_zero(int n)
{
	return get_last_num(n) == 0;
}

int main()
{
	int n;
	cin >> n;
	if(last_nine(n) && first(n) > last(n)) {
		cout << "No\n";
	} else if(last_zero(n) && first(n) < last(n)) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
	return 0;
}
