#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long count_t;

int get_offset(int n, int w)
{
	return (w - 1) * 500 + (n - 1);
}

// returns number of blocks for minimal stairs with given width
int f2(int w)
{
	int s = (2 + ( w - 1) * w) / 2;
	return s;
}

// returns number of variants of stairs for given number of blocks and given width of the stairs
// uses 'map' as cache for previously calculated data
count_t f(vector<count_t>& map, int n, int w)
{
	count_t cnt = -1;
	if(w == 1) {
		cnt = 1;
	} else if(w == 2) {
		cnt = (n - 1) / 2;
	} else {
		const int offset = get_offset(n,w);
		cnt = map[offset];

		if(cnt < 0) {
			cnt = 0;
			while(n > 0) {
				n -= w; // increase base floor height
				if(n > 0 && f2(w - 1) <= n) {
					cnt += f(map, n, w - 1);
				}
			}

			map[offset] = cnt;
		}
	}

	return cnt;
}

int main()
{
	int n;
	cin >> n;

	vector<count_t> map(33*510, -1); // -1 means not initialized

	count_t s = 0;

	for(int w = 2; /* loop until f() returns not zero */ ; ++w) {
		count_t cnt = f(map, n, w);
		if(cnt == 0) break;
		s += cnt;
	}

	cout << s << endl;

	return 0;
}
