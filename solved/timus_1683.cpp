#include <iostream>
#include <vector>
#include <algorithm>
//ac
using namespace std;

int main()
{
    unsigned long n;
    cin >> n;
    vector<unsigned long> v;
    while(n > 1) {
            unsigned int x = n / 2;
            unsigned int m = n - x;
            v.push_back(m);
            n = m;
    }
//    reverse(v.begin(), v.end());
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); ++i) {
            if(i != 0) cout << ' ';
            cout << v[i];
            }
    return 0;
}
