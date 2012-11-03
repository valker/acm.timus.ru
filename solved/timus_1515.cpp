#include <iostream>
#include <vector>
#include <assert.h>
//ac
using namespace std;

typedef unsigned long t;

t main2(const vector<t>& v)
{
    int s = v.size();
    t maxt = 0;
    for(int i = 0; i < s; ++i) {
        const t nk = v[i];
        if(nk <= (maxt + 1)) {
            maxt = nk + maxt;
        } else {
            break;
        }
    }
    return maxt + 1;
}

void test1()
{
    const t test[] = {
          1,
          2,
          4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384,
          32768, 65536, 100000, 131072, 200000, 262144, 300000, 400000, 500000,
          524288, 600000, 700000, 800000, 900000, 900001, 900002, 900003, 900004,
          900005, 900006, 900007, 900008, 900009, 900010, 900011, 900012, 900013,
          900014, 900015, 900016, 999000, 999001, 999002, 999003, 999004, 999005,
          999006, 999007, 999008, 999009, 1000000
    };
    vector<t> v(&test[0], &test[0] + sizeof(test) /sizeof(test[0]));
    t x = main2(v);
    cout << "result:" << x << endl;
    assert(x == 30938757);
}
void test2()
{
    const t test[] = {
          1
    };
    vector<t> v(&test[0], &test[0] + sizeof(test) /sizeof(test[0]));
    assert(main2(v) == 2);
}
void test3()
{
    const t test[] = {
          1,2
    };
    vector<t> v(&test[0], &test[0] + sizeof(test) /sizeof(test[0]));
    assert(main2(v) == 4);
}
void test4()
{
    const t test[] = {
          1,2,3
    };
    vector<t> v(&test[0], &test[0] + sizeof(test) /sizeof(test[0]));
    assert(main2(v) == 7);
}

int main()
{
//    test1();
//    test2();
//    test3();
//    test4();

    int n; cin >> n;
    vector<t> v;
    for(int i = 0; i < n; ++i) {
        t x; cin >> x;
        v.push_back(x);
    }

    t x = main2(v);
    cout << x << endl;
    return 0;
}
