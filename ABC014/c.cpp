// いもす法(1次元累積和)
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
const int MAX = 1e6;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vll res(MAX + 10, 0);
    REP(i, n)
    {
        ll a, b;
        cin >> a >> b;
        ++res[a];
        --res[b + 1];
    }
    // 累積和
    FOR(i, 1, MAX)
    res[i] += res[i - 1];
    // 最大値
    ll ans = 0;
    FOR(i, 0, MAX)
    ans = max(ans, res[i]);

    cout << ans << "\n";
    return 0;
}