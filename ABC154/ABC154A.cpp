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
    std::string s, t, u;
    int a, b;

    cin >> s >> t >> a >> b >> u;

    if (s == u)
    {
        a -= 1;
    }
    else
    {
        b -= 1;
    }

    cout << a << " " << b << "\n";
    return 0;
}
