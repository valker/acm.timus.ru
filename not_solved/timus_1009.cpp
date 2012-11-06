#include <iostream>

using namespace std;


int get_max_zero_digits(int n)
{
}

// n - n-characters
// k - base of number
int solve(int n, int k)
{
	const int max_not_zero_digits = get_max_not_zero_digits(n);
	for(int i = n; i >= max_not_zero_digits; --i) {
		const int zero_digits = n - i;
		const int zero_positions = get_zero_positions(n);
		const int number_of_variants = f(zero_digits, zero_positions);
	}
}

void test()
{
	assert(solve(2,10) == 90);
}

void main2()
{
	int n,k;
	cin >> n >> k;
	int result = solve(n, k);
	cout << result << endl;
}

int main()
{
#if 1
	test();
#else
	main2();
#endif
}

