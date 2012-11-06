#include <iostream>
#include <vector>
#include <numeric>
//ac
using namespace std;

double solve(const vector<int>& v)
{
	double sum = accumulate(v.begin(), v.end(), 0);
	double result = sum / v.size();
	return result;
}

void test()
{
}

int nt()
{
	int x;
	cin >> x;
	return x;
}

void main2()
{
	const int n = nt();
	vector<int> v; v.reserve(n);
	for(int i = 0; i < n; ++i) {
		v.push_back(nt());
	}
	double result = solve(v);
	cout.precision(6);
	cout << fixed << result << endl;
}

int main()
{
#if 0
	test();
#else
	main2();
#endif
}

