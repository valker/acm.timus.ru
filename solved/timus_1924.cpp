#include <iostream>
//ac
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s = 0;
    for(int i = 0; i < n; ++i) {
            s += (i + 1);
    }
    
    cout << ((s % 2 == 0) ? "black" : "grimy") << "\n";
    
    return 0;
}
