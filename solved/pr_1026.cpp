#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
//ac
using namespace std;

int main()
{
	int n, x, i;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	for(i = 0; i < n; ++i) {
		cin >> x;
		v.push_back(x);
	}

	{
		string s;
		getline(cin,s);
		getline(cin,s);
	}

	sort(v.begin(), v.end());

	cin >> n;
	for(i = 0; i < n; ++i) {
		cin >> x;
		cout << v[x-1] << endl;
	}

	return 0;
}
