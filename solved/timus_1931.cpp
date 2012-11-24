// timus_1931.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
//ac
using namespace std;

int main()
{
	int n; cin >> n;

	int max; cin >> max;
	int cnt = 0;
	int yi = 0;

	int maxcnt = 0;
	int maxx = max;
	int maxi = 0;

	for(int i = 1; i < n; ++i) {
		int y; cin >> y;
		int ycnt = 1;
		++cnt;
		if(cnt > maxcnt) {
			maxcnt = cnt;
			maxx = max;
			maxi = yi;
		}
		if(y < max) {
			max = y;
			cnt = 1;
			yi = i;
		}
	}

	cout << (maxi+1) << endl;

	return 0;
}

