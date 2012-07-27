// timus_1080.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <vector>

int main()
{
	using namespace std;
	int n;
	cin >> n;
	vector<int> v(n+1,-1);
	v[1] = 0;
	for(int i = 1; i <= n; ++i) {
		int c = v[i]; // color of current country
		int r = 1 - c; // color of neibour
		while(true) {
			int e; // neibour index
			cin >> e;
			if(e == 0) break;
			int ce = v[e]; // check is color defined already
			if(ce == -1) {
				// new country
				v[e] = r;
			} else if(ce != r) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	for(int i = 1; i <=n; ++i) {
		cout << v[i];
	}
	cout << '\n';
	return 0;
}

