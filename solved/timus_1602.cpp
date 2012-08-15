// timus_1602.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream>

using namespace std;

typedef float value;

double calc(int n, int k, value u, value v, int i)
{

	if(i == 1) {
		return (n - 1) * u;
	}

	value t1 = (k - 1) * v + 15.0;
	value t2 = (n - i) * u;
	value t = std::max(t1,t2);
	
	t += (i - 1) * v;

	t += 5.0;

	t += (i - 1) * v;

	return t;
}

int main()
{
	int n,k;
	value u,v;
	cin >> n >> k >> u >> v;

	int besti = -1;
	value besttime = numeric_limits<value>::max();

	for(int i = n; i > 0; --i) {
		value t = calc(n,k,u,v,i);
		if((t+numeric_limits<value>::epsilon()) < besttime) {
			besttime = t;
			besti = i;
		}
	}

	cout << besti << '\n';

	return 0;
}
