#include <iostream>
#include <vector>
#include <algorithm>
//ac
using namespace std;

int main()
{
	vector<long> v;
	int n;
	cin >> n;
	v.reserve(n);
	for(int i = 0; i < n; ++i) {
		long x;
		cin >> x;
		v.push_back(x);
	}
	nth_element(
		v.begin(),
		v.begin() + v.size() / 2,
		v.end());
	cout << *(v.begin() + v.size() / 2) << '\n';
	return 0;
}
