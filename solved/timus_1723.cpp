#include <iostream>
#include <string>
#include <string.h>
//ac
using namespace std;

// n - n-characters
// k - base of number
string solve(const string& s)
{
	char x[26];
	memset(&x[0], 0, sizeof(x));
	int max = 0;
	int maxc = -1;
	for(int i = 0; i < s.size(); ++i) {
		char c = s[i];
		int off = c - 'a';
		x[off]++;
		if(x[off] > max) {
			max = x[off];
			maxc = off;
		}
	}

	return string(1, static_cast<char>(maxc + 'a'));
}

void test()
{
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
#if 0
	test();
#else
	main2();
#endif
}

