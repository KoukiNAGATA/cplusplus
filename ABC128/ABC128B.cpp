#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
//以下ak_johoさんのを拝借してみる. 使いやすそう.
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; //店数
    cin >> n;
    map<string, map<int, int>> stores;
    FOR(i, 1, n)
    {
        string s;
        int p;
        cin >> s >> p;
        stores[s][p] = i;
    }
    stores::sort;
    FOR(i, 1, n)
    {
        cout << stores[s][p] << "\n";
    }
    return 0;
}