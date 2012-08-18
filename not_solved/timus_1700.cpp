// timus_1700.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <algorithm>

using namespace std;

// storage that allows to contains unique 
struct UNIQUE_STRING_STORAGE {

	map<string, int> storage_;

	int add(const string& value) {

		map<string,int>::iterator it = storage_.find(value);
		if(it == storage_.end()) {
			// add new item
			const int index = storage_.size();
			storage_.insert(make_pair(value, index));
			return index;
		} else {
			// return existing
			return it->second;
		}
	}

	int find(const string& value ) {
		return storage_[value];
	}

	// output those items which indexes are in vectir
	void output(ostream& out, const vector<int>& indexes) {
		//for(size_t i = 0; i < indexes.size(); ++i) {
		//	if(i != 0) out << ' ';
		//	out << storage_[indexes[i]];
		//}
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

		int ob_index = object_storage.add(ob);

		size_t next = s.find_first_not_of(':', delim);
		while(true) {
			if(next == string::npos) break;
			size_t delim = s.find(' ', next);
			string attribute = s.substr(next, delim - next);

			int attribute_index = attrib_storage.add(attribute);

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
		while(from != string::npos && (!attributes.empty() || first)) {
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

