#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct Names {
	Names() : next_(0) {}
	int GetId(const string& s) {
		map<string,int>::iterator it = m_.find(s);
		if(it == m_.end()) {
			int i = next_++;
			m_[s] = i;
			return i;
		} else {
			return it->second;
		}
	}
private:
	map<string, int> m_;
	int next_;
};

struct Graph {
};

int main()
{
	string gateway;
	getline(cin, gateway);
	vector<string> cells;
	Names names;
	Graph graph;
	while(true) {
		string s;
		getline(cin, s);
		if(s == "#") break;
		// split string into pair
		size_t minus = s.find('-');
		string left = s.substr(0, minus);
		string right = s.substr(minus + 1);
		names.GetId(left);
		names.GetId(right);
	}
	return 0;
}

