#include <iostream>
#include <map>
#include <string>
//ac
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	getline(cin,s);
	map<string,int> m;
	for (int i = 0; i < n; ++i) {
		getline(cin,s);
		++m[s];
		if(m[s] == 2) {
			cout << s << '\n';
		}
	}
	
	return 0;
}
