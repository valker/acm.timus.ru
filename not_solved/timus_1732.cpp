// timus_1732.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

void censor(string::iterator begin, string::iterator end)
{
	while(begin != end) {
		if(*begin != ' ') {
			*begin = '_';
		}
		++begin;
	}
}

template<class It>
vector<int> horspool_prepare(It from, It to, int m, int FROM, int TO)
{
	const int m = distance(from, to);
	const int ASIZE = TO - FROM; // size of the alphabet

	vector<int> bm_bc(ASIZE, m);

	const It toj = to - 1;
	for(It fromj = from; fromj != toj; ++fromj) {
		bm_bc[*fromj - FROM] = m - distance(from, fromj) - 1;
	}

	return bm_bc;
}

template<class It1, class It2>
It1 horspool_search(It1 from1, It1 to1, It2 from2, It2 to2)
{
	// preparin
	const int m = distance(from2, to2);
	static const int FROM = ' '; // start character of the alphabet
	static const int TO = 'z'+1; // last character of the alphabet
	vector<int> bm_bc(horspool_prepare(from2, to2, m, FROM, TO));

	const char lastch = *(from2 + m - 1);
	int i = 0;
	const int n = distance(from1, to1);
	while(i <= n - m) {
		char ch = *(from1 + m - 1);
		if(ch == lastch && equal(from1, from1 + m, from2)) {
			return from1 + i;
		}

		int offset = bm_bc[ch - FROM];
		i += offset;
		from1 += offset;
	}

	return to1;
}

void ex(string& src, const string& dst)
{
	string::iterator it = src.begin(), en = src.end();
	string::const_iterator dit = dst.begin(), den = dst.end();
	while(dit != den) {
		// find word in destination stream
		string::const_iterator space = find(dit, den, ' ');

		string::const_iterator w_begin = dit;
		string::const_iterator w_end = space;

		dit = space;

		if(space != den) {
			// set up 'dit' to start of next word
			++dit;
		}

		// search word from dst in src substring
		//string::iterator wrd = search(it, en, w_begin, w_end);
		string::iterator wrd = horspool_search(it, en, w_begin, w_end);
		if(wrd == en) {
			// word is not found
			src = "I HAVE FAILED!!!";
			return;
		}

		if(it != wrd) {
			// word is not at the begin of the range
			string::iterator last = (*(wrd-1) == ' ') ? wrd - 1: wrd; 
			//fill(it, last, '_');
			//replace_if(it, last, isalpha, '_');
			censor(it, last);
		}
		it = wrd + distance(w_begin, w_end);
		if(it != en) {
			if(*it != ' ') {
				*it = '_';
			}
			++it;
		}
	}

	if(it != en) {
		--it;
		//replace_if(it, en, isalpha, '_');
		censor(it, en);
	}

	return;
}

int main()
{
	string src, dst;

#if 1
	src.reserve(100010);
	dst.reserve(100010);
	getline(cin, src);
	getline(cin, dst);
	ex(src,dst);
	cout << src << '\n';
#else
	src = "adsa asdasd qweqwe aa dads abba aacc";       dst = "aa bb cc";      ex(src,dst); assert(src == "____ ______ ______ aa ____ _bb_ __cc");
	src = "Preved to Medved";       dst = "Preved Me";      ex(src,dst); assert(src == "Preved __ Me____");
	src = "hhahaphapphappyhappyhh"; dst = "hap happ hh";    ex(src,dst); assert(src == "___hap____happ______hh");
	src = "lossiblossible";         dst = "lossible";       ex(src,dst); assert(src == "______lossible");
	src = "abcx abcxx abcxx";       dst = "abc abcx abc x"; ex(src,dst); assert(src == "abc_ abcx_ abc_x");
	src = "this is impossible";     dst = "im possible";    ex(src,dst); assert(src == "I HAVE FAILED!!!");
#endif

	return 0;
}

