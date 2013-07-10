#include <iostream>
#include <vector>
//#include <assert.h>
//1225
using namespace std;

typedef long long tt;
vector<tt> v(100);

tt getmc(tt n);

tt getm(tt n)
{
	if(n == 1) return 2;
	if(n == 2) return 2;
	tt a1 = getmc(n - 1);
	tt a2 = getmc(n - 2);
	tt a3 = a1 + a2;
	return a3;
}

tt getmc(tt n)
{
	if(v[n] == 0) {
		tt m = getm(n);
		v[n] = m;
	}
	return v[n];
}

int main(int argc, char* argv[])
{
	//assert(getmc(3) == 4);
	//assert(getmc(4) == 6);
	//assert(getmc(5) == 10);
	//assert(getmc(6) == 16);
	//assert(getmc(7) == 26);
	//assert(getmc(8) == 42);
	//assert(getmc(45) == 2269806340);
	tt n;
	cin >> n;
	tt m = getmc(n);
	cout << m << endl;
	return 0;
}

