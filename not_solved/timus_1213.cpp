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
	void new_edge(pair<int,int> e) {
		//TODO: should be implemented
	}
	int get_mst_size() { 
		//TODO: should be implemented
		return 0; }
};

pair<int,int> read_edge(istream& in, Names& names)
{
	string s;
	getline(cin, s);
	if(s == "#") return make_pair(-1,-1);
	size_t minus = s.find('-');
	string left = s.substr(0, minus);
	string right = s.substr(minus + 1);
	const int left_id = names.GetId(left);
	const int right_id = names.GetId(right);
	return make_pair(left_id, right_id);
}

int main()
{
	string gateway;
	getline(cin, gateway);
	Names names;
	Graph graph;
	while(true) {
		const pair<int,int> e = read_edge(cin, names);
		if(e.first == -1) break;
		graph.new_edge(e);
	}
	
	const int mst_size = graph.get_mst_size();

	cout << mst_size << endl;

	return 0;
}

