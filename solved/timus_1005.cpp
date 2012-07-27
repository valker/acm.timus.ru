// timus_1005.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

void process(const vector<int>& v, int index, vector<int>& includes, int sum, int& best_sum)
{
	// check finish condition
	if(index == v.size()) return;

	// process when not included
	process(v, index+1, includes, sum, best_sum);

	// process when included
	includes.push_back(v[index]);
	int s = 0;
	for(int i = 0; i < includes.size(); ++i) {
		s+=includes[i];
	}
	int s2 = sum - s;
	int diff = abs(s - s2);
	if(diff < best_sum) best_sum = diff;
	process(v, index+1, includes, sum, best_sum);
	includes.pop_back();
}	

int main2(const vector<int>& v)
{
	int sum = 0;
	for(int i = 0; i < v.size(); ++i) sum+=v[i];
	vector<int> includes;
	includes.reserve(20);
	int best_sum = numeric_limits<int>::max();
	process(v,0,includes, sum, best_sum);
	return best_sum;
}

template<int n>
int x(int arr[n])
{
	vector<int> v(&arr[0], &arr[0]+n);
	return main2(v);
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.reserve(n);
	for(int i = 0 ; i < n ; ++i) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	cout << main2(v) << '\n';

	//{int xx[] = {1,2,3}; assert(x< (sizeof(xx) / sizeof(xx[0])) >(xx) == 0);}
	//{int xx[] = {1, 4, 5, 6, 7, 9}; assert(x< (sizeof(xx) / sizeof(xx[0])) >(xx) == 0);}
	//{int xx[] = {10, 9, 8, 7, 2}; assert(x< (sizeof(xx) / sizeof(xx[0])) >(xx) == 0);}
	//{int xx[] = {9, 8, 6, 5, 4, 1}; assert(x< (sizeof(xx) / sizeof(xx[0])) >(xx) == 1);}

	return 0;
}
