#include <iostream>
#include <vector>
#include <algorithm>
//ac
using namespace std;

int main()
{

	vector<int> v(100000);
	// prepare data
	v[0] = 0;
	v[1] = 1;
	for(int i = 1; i < 100000 / 2; ++i) {
		v[i * 2]     = v[i];
		v[i * 2 + 1] = v[i] + v[i+1];
	}

	while(true)
	{

		int n;
		cin >> n;
		if(n == 0) break;
		vector<int>::iterator me = max_element(v.begin(), v.begin() + n + 1);
		cout << (*me) << '\n';
	}
	return 0;
}
