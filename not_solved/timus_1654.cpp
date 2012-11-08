#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

string solve(const string& inp)
{
	std::string xx;
	xx.assign(inp.begin(), inp.end());
	size_t pos = 0;
	size_t len = xx.size();

// abbbccd
// 0123456
// len = 7

	while(pos < len) {
		if( pos < (len - 2)) {
			if(xx[pos] == xx[pos + 1]) {
				// find end of this sequence
				size_t end = pos + 1;
				while(end < len) {
					if(xx[end] != xx[pos]) {
						break;
					}
				}
				xx.erase(pos, end - pos);
				if(pos > 0) {
					--pos;
				}
				len = xx.size();
			} else {
				++pos;
			}
		} else {
			++pos;
		}
	}

	return xx;
}

void test()
{
	string inp ="wwstdaadierfflitzzz";
	string result ="stierlitz"; 
	assert(solve(inp) == result);
}

void main2()
{
	string s;
	getline(cin, s);
	s = solve(s);
	cout << s << endl;
}

int main()
{
#if 1
	test();
#else
	main2();
#endif
}

