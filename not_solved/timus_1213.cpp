#include <iostream>
#include <string>
#include <map>
//ac
using namespace std;

int main()
{
	string gateway;
	getline(cin, gateway);
	map<string, bool> m;
	m[gateway] = true;

	while(true) {
		string s;
		getline(cin, s);
		if(s[0]=='#') break;
		size_t d = s.find('-');
		string left = s.substr(0, d);
		string right = s.substr(d + 1);
		m[left] = true;
		m[right] = true;
	}
	
	cout << (m.size() - 1) << endl;

	return 0;
}

