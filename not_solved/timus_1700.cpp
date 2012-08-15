// timus_1700.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>

using namespace std;

struct UNIQUE_STRING_STORAGE {
	vector<string> storage_;
	vector<int> indexes_;

	struct Pred {
		Pred(const vector<string>& s, const string& v) : s_(s),v_(v) {}
		const vector<string>& s_;
		const string& v_;

		const string& get(int index) const {
			if( index == -1) return v_;
			return s_[index];
		}

		bool operator()(int left, int right) const {
			return get(left) < get(right);
		}
	};

	int push(const string& value) {
		vector<int>::iterator it = lower_bound(indexes_.begin(), indexes_.end(), -1, Pred(storage_, value));
		if(it != indexes_.end()) {
			if(storage_[*it] == value) {
				return *it;
			} else {
			}
		}
	}

	int find(const string& value ) {
		vector<int>::iterator it = lower_bound(indexes_.begin(), indexes_.end(), -1, Pred(storage_, value));
		return *it;
	}

	void output(ostream& out, const vector<int>& indexes) {
		for(int i = 0; i < indexes.size(); ++i) {
			if(i != 0) out << ' ';
			out << storage_[indexes[i]];
		}
	}
};

struct OBJECT_STORAGE : public UNIQUE_STRING_STORAGE {};

struct ATTRIB_STORAGE : public UNIQUE_STRING_STORAGE {};

struct RELATION_STORAGE {
	void push(int object, int attribute) {
		// TODO: should be done
	}

	vector<int> find(int object) const {
		// TODO: should be done
		return vector<int>();
	}
};

int main()
{
	int n;
	cin >> n;

	OBJECT_STORAGE object_storage;
	ATTRIB_STORAGE attrib_storage;
	RELATION_STORAGE relation_storage;

	for(int i = 0; i < n; ++i) {
		string s;
		getline(cin, s);
		size_t delim = s.find(':');
		string ob = s.substr(0, delim - 0);

		int ob_index = object_storage.push(ob);

		size_t next = s.find_first_not_of(':', delim);
		while(true) {
			if(next == string::npos) break;
			size_t delim = s.find(' ', next);
			string attribute = s.substr(next, delim - next);

			int attribute_index = attrib_storage.push(attribute);

			relation_storage.push(ob_index, attribute_index);

			next = s.find_first_not_of(' ', delim);
		}
	}

	int m;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		string s;
		getline(cin, s);
		size_t from = 0;
		bool first = true;
		vector<int> attributes;
		while(from != string.npos && (!attributes.empty() || first)) {
			const size_t space = s.find(' ', from);
			const string x = s.substr(from, (space == string::npos) ? space : (space - from));
			const int obj_index = object_storage.find(x);
			vector<int> at2 = relation_storage.find(obj_index);
			// process x
			if(first) {
				// take list of attribute from given object
				attributes.swap(at2);
				first = false;
			} else {
				// find interselect of two vectors
			}
			from = s.find_first_not_of(' ', space);
		}

		if(attributes.empty()) {
			cout << "No solution.\n";
		} else {
			attrib_storage.output(cout, attributes);
		}
	}

	return 0;
}

