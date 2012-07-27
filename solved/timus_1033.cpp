// timus_1033.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int gc(int x, int y, int w) {
	return y * w + x;
}

struct crd {
	crd(int xx, int yy) : x(xx), y(yy) {}
	int x;
	int y;
};

#if 0
#include <fstream>
	fstream fin("1033.txt");
#define cin fin
#endif

int main()
{
	// get param
	int n;
	cin >> n;
	{string s; getline(cin,s);}

	// create wall around
	const int N = n + 2;
	vector<int> m(N * N, 0);

	// 0 - empty
	// 1 - wall
	// 2 - achievable empty
	// 3 - 
	for(int i = 0; i < N; ++i) {
		m[gc(i,0,N)] = 1;
		m[gc(i,N-1,N)] = 1;
		m[gc(0,i,N)] = 1;
		m[gc(N-1,i,N)] = 1;
	}

	// read labirinth
	for(int y = 0; y < n; ++y) {
		string s;
		getline(cin, s);
		for(int x = 0; x < s.length(); ++x) {
			m[gc(1+x, 1+y, N)] = ((s[x] == '#') ? 1 : 0);
		}
	}

	// update map according to achievability
	list<crd> L;
	L.push_back(crd(1,1));
	L.push_back(crd(n,n));
	while(!L.empty()) {
		crd coord = L.front();
		int x = coord.x;
		int y = coord.y;

		m[gc(x, y, N)] = 2;
		if(x > 0     && m[gc(x-1,y,N)] == 0) { L.push_back(crd(x-1,y)); }
		if(x < N - 1 && m[gc(x+1,y,N)] == 0) { L.push_back(crd(x+1,y)); }
		if(y > 0     && m[gc(x,y-1,N)] == 0) { L.push_back(crd(x,y-1)); }
		if(y < N - 1 && m[gc(x,y+1,N)] == 0) { L.push_back(crd(x,y+1)); }
		L.pop_front();
	}

	m[gc(0,1,N)]=0;
	m[gc(1,0,N)]=0;
	m[gc(n,n+1,N)]=0;
	m[gc(n+1,n,N)]=0;

	int cnt = 0;
	// find each egde 2<->1 and count it
	for(int y = 1; y <= n; ++y) {
		for(int x = 1; x <= n; ++x) {
			if(m[gc(x,y,N)] == 2) {
				// look around
				if(m[gc(x-1,y,N)] == 1) {++cnt; 
//				cout << x << y << (x - 1) << y;
				}
				if(m[gc(x+1,y,N)] == 1) {++cnt; 
//				cout << x << y << (x + 1) << y;
				}
				if(m[gc(x,y-1,N)] == 1) {++cnt; 
//				cout << x << y << x << (y - 1);
				}
				if(m[gc(x,y+1,N)] == 1) {++cnt; 
//				cout << x << y << x << (y + 1);
				}
			}
		}
	}

	cout << (cnt * 9) << '\n';

	return 0;
}

