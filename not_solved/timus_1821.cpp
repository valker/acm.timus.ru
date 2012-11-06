#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <stdio.h>
//wa
using namespace std;

unsigned int get_time(const string& min, const string& sec)
{
	unsigned int min_value;
	sscanf(min.c_str(), "%d", &min_value);
	float sec_value;
	sscanf(sec.c_str(), "%f", &sec_value);
	sec_value *= 10;
	min_value *= 600;
	min_value += sec_value;
	return min_value;
}

int main()
{
	int n; cin >> n; string tmp; getline(cin, tmp);
	unsigned int min_time = std::numeric_limits<unsigned int>::max();
	vector<string> names;
	unsigned int delta = 0;
	for(int i = 0; i < n; ++i, delta += 300) {
		string s;
		getline(cin, s);
		const size_t space = s.find(' ');
		const size_t colon = s.find(':', space);
		const string name = s.substr(0, space);
		const string minutes = s.substr(space + 1, colon - space - 1);
		const string seconds = s.substr(colon + 1);
		const unsigned int time = get_time(minutes, seconds) - delta;
		if(time < min_time) {
			cout << "t:" << name << " " << time << endl;
			names.push_back(name);
			min_time = time;
		}
	}

	cout << names.size() << endl;
	sort(names.begin(), names.end());
	for(int i = 0; i < names.size(); ++i) {
		cout << names[i] << endl;
	}

	return 0;
}

