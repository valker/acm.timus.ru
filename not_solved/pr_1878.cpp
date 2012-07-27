// WA7
#include <iostream>
#include <vector>
#include <algorithm>

#include <fstream>
using namespace std;

int main()
{
	fstream fin("test_1878.txt");
	// read input
	vector<int> v;
	v.reserve(16);
	for(int i = 0; i < 16; ++i) {
		int x;
		fin >> x;
		v.push_back(x);
	}

	// count color in left-up square
	vector<int> c(4);
	int n[] = { 0, 1, 4, 5 }; // up left
	int nur[] = { 2, 3, 6, 7 }; // up right
	int ndl[] = { 8, 9, 12, 13 }; // down left
	int ndr[] = { 10, 11, 14, 15}; // down right
	for(int i = 0; i < 4; ++i) {
		int color = v[n[i]];
		--color;
		c[color]++;
	}

	// find number of element in this square
	vector<int>::iterator it = max_element(c.begin(), c.end());
	int cnt = *it;
	int clr = distance(c.begin(), it) + 1;
	if(cnt == 1) {
		// all diff
		cout << "4\n";
	} else if(cnt == 2 || cnt == 3) {
		int turn = 0;
		// find in which square the rest
		for(int i = 0; i < 4; ++i) {
			if(v[ndl[i]] == clr) { ++turn; break; }
		}
		for(int i = 0; i < 4; ++i) {
			if(v[nur[i]] == clr) {  ++turn; break; }
		}
		for(int i = 0; i < 4; ++i) {
			if(v[ndr[i]] == clr) {  turn += 2; break; }
		}
		cout << turn << '\n';
	} else {
		// all on the place
		cout << "0\n";
	}
	return 0;
}

