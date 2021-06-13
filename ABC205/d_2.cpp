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
    // input
    int n, q;
    cin >> n >> q;
    vll a(n);
    REP(i, n)
    cin >> a[i];
    // a[i]以下のいずれとも異なる正の整数の個数=良い整数の個数の配列
    vll low(n);
    REP(i, n)
    low[i] = a[i] - (i + 1);
    REP(i, q)
    {
        ll k;
        cin >> k;
        // k以下の良い整数の個数
        auto idx = lower_bound(low.begin(), low.end(), k) - low.begin();
        if (idx == n) // kがa[n]以下の良い整数の個数より大きい
            cout << a[n - 1] + (k - low[n - 1]) << '\n';
        else // a[i]−1から low[i]−k個戻ったのが答え
            cout << (a[idx] - 1) - (low[idx] - k) << '\n';
    }
    return 0;
}