// ワーシャルフロイド法。全点対最短経路
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

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vll a(n + 10, 0);
    vll sum(n + 10, 0);

    // 入力
    FOR(i, 1, n)
    cin >> a[i];
    // 累積和
    sum[0] = 0;
    FOR(i, 1, n)
    sum[i] = sum[i - 1] + a[i];

    FOR(i, 1, n)
    {
        ll ans = 0;
        FOR(j, 0, n - i)
        {
            ans = max(ans, sum[j + i] - sum[j]);
        }
        cout << ans << '\n';
    }
    return 0;
}
