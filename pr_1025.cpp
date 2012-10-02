#include<vector>
#include<iostream>
#include<algorithm>
//ac
int main()
{
	using namespace std;
	int n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	for(int i = 0; i < n; ++i ) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int i = v.size() / 2; // 1 -> 0; 2,3 -> 1; 4,5 -> 2
	++i;
	vector<int>::iterator en = v.begin() + i, it = v.begin();
	int s = 0;
	for(;it != en; ++it) {
		int x = *it;
		x = x / 2 + 1;
		s += x;
	}

	cout << s << '\n';
	return 0;
}
