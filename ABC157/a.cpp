#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int inf = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;

    cin >> n;
    if (n % 2)
    { //2で割り切れない
        cout << n / 2 + 1 << "\n";
        return 0;
    }
    else
    {
        cout << n / 2 << "\n";
        return 0;
    }
}