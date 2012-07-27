// timus_1020.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	double r;
	int n;
	cin >> n >> r;
	vector<double> x,y;
	x.reserve(n);
	y.reserve(n);
	for(int i = 0; i < n; ++i) {
		double xx,yy;
		cin >> xx >> yy;
		x.push_back(xx);
		y.push_back(yy);
	}

	double s = 0;
	for(int i = 0; i < n; ++i) {
		int i2 = i + 1; if(i2 == n) i2 = 0;
		double dx = x[i]-x[i2];   dx = dx * dx;
		double dy = y[i] - y[i2]; dy = dy * dy;
		s += sqrt(dx + dy);
	}

	const double pi = 3.1415926535897932384626433832795;

	double ork = 2 * pi * r;

	s += ork;
	std::cout.setf(ios_base::fixed, ios_base::floatfield);
    std::cout.precision(2);
    cout << s << '\n';

	return 0;
}

