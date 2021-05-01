#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const ll INF = 1LL << 60;
const int MAX = 100000;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    vll a(k + 1, 0);
    a[1] = 7 % k;
    // mod kで分類→鳩の巣原理よりkケ調べれば十分
    FOR(i, 2, k)
    a[i] = (a[i - 1] * 10 + 7) % k;

    FOR(i, 1, k)
    if (a[i] == 0)
    {
        cout << i << "\n";
        return 0;
    }
    cout << -1 << "\n";
    return 0;
}