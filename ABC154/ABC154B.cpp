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
    string s;

    cin >> s;
    int m = (int)(s.length());
    vector<char> t(m, 'x');
    string ans = string(t.begin(), t.end());

    cout << ans << "\n";
    return 0;
}