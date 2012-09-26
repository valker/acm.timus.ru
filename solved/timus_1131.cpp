#include <iostream>
#include <cassert>

using namespace std;

int read_int()
{
	int x;
	cin >> x;
	return x;
}

int get_log2(int x)
{
	int targetlevel = 0;
	while (x >>= 1) ++targetlevel;
	return targetlevel;
}

int get_pow2(int x)
{
	int v = 1;
	while(x > 0) {
		v *= 2;
		--x;
	}

	return v;
}

int f(int n, int k)
{
	const int log2k = 1 + get_log2(k); // count of steps where wires don't limit avalanche
	const int n_avalanch = get_pow2(log2k); // count of computers available after not limited steps
	if(n_avalanch > n) {
		const int log2n = get_log2(n);
		const int result  = get_pow2(log2n) == n ? log2n : (log2n + 1);
		return result;
	}
	const int n_rest = n - n_avalanch;
	const int steps = (n_rest + (k - 1)) / k;
	const int total_steps = log2k + steps;
	return total_steps;
}

int main()
{
	#if 0
	assert(f(1,1) == 0);
	assert(f(2,1) == 1);
	assert(f(3,1) == 2);
	assert(f(4,1) == 3);
	assert(f(5,1) == 4);

	assert(f(1,2) == 0);
	assert(f(2,2) == 1);
	assert(f(3,2) == 2);
	assert(f(4,2) == 2);
	assert(f(5,2) == 3);

	assert(f(1,3) == 0);
	assert(f(2,3) == 1);
	assert(f(3,3) == 2);
	assert(f(4,3) == 2);
	assert(f(5,3) == 3);
#endif

	const int n = read_int(); // count of computers
	const int k = read_int(); // count of wires
	cout << f(n,k) << endl;

	return 0;
}
