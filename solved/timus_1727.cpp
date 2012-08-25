// timus_1727.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int get_sum(int n)
{
	int s = 0;
	while(n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}

bool cmp_by_snd(const pair<int,int>& left, const pair<int,int>& right)
{
	return left.second < right.second;
}

struct storage {
	set<int> parts_;

	vector<pair<int,int> > numbers_;

	storage() {
		numbers_.reserve(10000);
		for(int i = 1; i < 10000; ++i) {
			numbers_.push_back(make_pair(i, get_sum(i)));
		}

		sort(numbers_.begin(), numbers_.end(), cmp_by_snd);
	}

	int get_next(int n)
	{
		pair<int,int> x(0,n);
		vector<pair<int,int> >::iterator it =
			lower_bound(numbers_.begin(), numbers_.end(), x, cmp_by_snd);
		if(it == numbers_.end()) {
			--it;
		}
		int value = it->first;
		numbers_.erase(it);
		return value;
	}

	void insert(int value) { parts_.insert(value); }

	void output(ostream& out)
	{
		out << parts_.size() << endl;
		bool first = true;
		for(set<int>::iterator it = parts_.begin(), en = parts_.end(); it != en; ++it) {
			if(!first) {
				out << ' ';
			} else {
				first = false;
			}
			out << *it;
		}
	}
};

int main()
{
	int n;
	cin >> n;
	storage parts;
	while(n > 0) {
		int next = parts.get_next(n);
		parts.insert(next);
		n -= get_sum(next);
	}

	parts.output(cout);

	return 0;
}

