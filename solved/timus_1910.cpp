// timus.cpp : Defines the entry point for the console application.
//1910. Руины титанов: сокрытый вход

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	vector<int> v;
	cin >> n;
	v.reserve(n);
	int i;
	for(i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int s_best = 0;
	int i1_best = -1;
	int i1 = 0;
	int i2 = 2;
	for(; i2 < n; ++i1, ++i2) {
		int s = std::accumulate(
			v.begin() + i1,
			v.begin() + i2 + 1,
			0
			);
		if(s > s_best) {
			s_best = s;
			i1_best = i1;
		}
	}

	cout << s_best << " " << (i1_best + 1 + 1) << "\n";

	return 0;
}

