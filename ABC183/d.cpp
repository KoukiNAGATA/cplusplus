// いもす法(1次元累積和)
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 200000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

// 区間を終端時刻で大小比較する関数
bool cmp(const P &a, const P &b)
{
    return a.second < b.second;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, w;
    cin >> n >> w;
    vll res(MAX + 10, 0);
    REP(i, n)
    {
        ll s, t, p;
        cin >> s >> t >> p;
        res[s] += p;
        res[t] -= p;
    }
    // 累積和
    FOR(i, 1, MAX)
    res[i] += res[i - 1];
    // 最大値
    ll ma = 0;
    REP(i, MAX)
    ma = max(ma, res[i]);

    if (ma > w)
        cout << "No"
             << "\n";
    else
        cout << "Yes"
             << "\n";
    return 0;
}