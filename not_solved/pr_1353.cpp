#include <iostream>
#include <vector>
#include <algorithm>
//in progress
using namespace std;

typedef int cnt_t;

int get_offset(int s, int l)
{
	return (l - 1) * 80 + s - 1;
}
cnt_t f(vector<cnt_t>& map, int s, int l)
{
	if(l == 1) {
		return 1;
	} else {
		const int offset = get_offset(s,l);
		cnt_t sum = map[offset];
		if(sum < 0) {
			const int mx_i = std::min(9, s);
			sum = 0;
			for(int i = 0; i <= mx_i; ++i) {
				sum += f(map, s - i, l - 1);
			}
			map[offset] = sum;
		}
		return sum;
	}
}

cnt_t g(vector<int>& digits, int s) {

	int mxi = std::min(s, 9);
	for(int i = 0; i <= mxi; ++i) {
		digits.push_back(i);

	}

}

int main()
{
	vector<cnt_t> map(8*80, -1);
	int s;
	//cin >> s;

	s = 1;

	cnt_t fs = 0;
	vector<int> digits;
	digits.reserve(10);
	for(int l = 1; l < 10; ++l) {
		fs += f(map, s, l, digits);
	}

	if(s == 1) ++fs;

	cout << fs << endl;
	return 0;
}
