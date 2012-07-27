// timus_1837.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<char> source_string;

typedef source_string::const_iterator sci;

// interval string
struct mstring
{
	mstring(sci b, sci e) 
		: begin_(b)
 		, end_(e)
		{}
	
	// part of basic_string<> interface
	int length() const { return distance(begin_, end_); }
	
	sci begin() const { return begin_; }
	
	sci end() const { return end_; }
	
	char operator[](int offset) const { return *(begin_ + offset); }
private:
	sci begin_;
	sci end_;
};

// output interval string to the output stream
ostream& operator<<(ostream& o, const mstring& ms)
{
	copy(ms.begin(), ms.end(), ostream_iterator<char>(cout));
	return o;
}

// compare interval string (for 'sort')
bool operator<(const mstring& left, const mstring& right)
{
	bool result = lexicographical_compare(left.begin(), left.end(), right.begin(), right.end());
	//cout << "cmp [" << left << "] and [" << right << "] result = " << result << "\n";
	return result;
}

// compare interval string (for 'unique')
bool operator==(const mstring& left, const mstring& right)
{
	return (!(left < right))  && (!(right < left));
}

template<class T>
struct Splitter
{
	Splitter(const T& s, char delimiter)
		: from_(s.begin())
		, end_(s.end())
	{
		delimiter_[0] = delimiter;
	}
	
	bool eof() const { return from_ == end_; }
	
	// precondition: not eof()!!!
	mstring next() {
		// find next delimiter
		sci it = find_first_of(from_, end_, &delimiter_[0], &delimiter_[0] + 1);
		sci from = from_;
		from_ = it;
		
		if(it != end_) {
			++from_;
		}
		
		return mstring(from, it);
	}
	
	const sci end_;
	sci from_;
	char delimiter_[1];
};

struct member_info {
	mstring name_;
	vector<int> teams_;
};

struct ByName {
	ByName(const mstring& name) : name_(name) {}
	const mstring& name_;
	bool operator()(const member_info& info) {
		return info.name_ == name_;
	}
};

int main()
{
	int n;
	string s;
	cin >> n; getline(cin, s);
	source_string ss;
	ss.assign((istreambuf_iterator<char>(cin)),istreambuf_iterator<char>());
	Splitter<source_string> teams(ss, '\n');
	vector<member_info> people;
	int team_index = 0;
	while(!teams.eof()) {
		++team_index;
		mstring team = teams.next();
		Splitter<mstring> members(team, ' ');
		while(!members.eof()) {
			mstring member = members.next();
			vector<member_info>::iterator it = find_if(people.begin(), people.end(), ByName(member));
			if(it != people.end()) {
				// increase team list
				it->teams_.push_back(team_index);
			} else {
				// add new person
				people.push_back(member_info());
				people.back().name_ = member;
				people.back().teams_.push_back(team_index);
			}
		}
	}

	for(int i = 0; i < people.size(); ++i) {
		cout << people[i].name_ << '\n';
		for(int j = 0; j < people[i].teams_.size(); ++j) {
			cout << people[i].teams_[j] << ' ';
		}
		cout << "\n---\n";
	}

	return 0;
}

