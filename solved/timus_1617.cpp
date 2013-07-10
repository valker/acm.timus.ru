//1617

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	cin >> n;
	vector<int> c(101);
	int i;
	for(i = 0; i < n; ++i) {
		int x; 
		cin >> x;
		x -= 600;
		c[x]++;
	}

	int s = 0;
	for(i = 0; i < 101; ++i) {
		s += c[i] / 4;
	}

	cout << s << endl;

	return 0;
}

