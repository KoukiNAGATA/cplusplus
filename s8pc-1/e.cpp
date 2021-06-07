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
const int INF = 1 << 30;
const int MAX = 100000;
const int MOD = 1000000007;

ll modpow(ll a, ll n)
{ //二分累乗法により、Nを2の累乗の和に分解してO(logN)で求める
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, q;
    cin >> n >> q;
    vll a(n + 1, 0);
    FOR(i, 1, n)
    cin >> a[i];
    // 距離の累積和(点1からの距離)
    vll sum(n + 1, 0);
    FOR(i, 1, n)
    sum[i] = sum[i - 1] + modpow(a[i - 1], a[i]);

    ll ans = 0;
    int c = 1;
    int prev = c;
    // クエリ処理(一つ前を保持)
    REP(i, q)
    {
        prev = c;
        cin >> c;
        ans += abs(sum[prev] - sum[c]);
        ans %= MOD;
    }
    // 点1に帰ってくる
    ans += abs(sum[1] - sum[c]);
    ans %= MOD;
    cout << ans << "\n";
    return 0;
}