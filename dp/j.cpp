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
    int n, a[303], c[4];
    double dp[303][303][303];
    cin >> n;
    REP(i, n)
    cin >> a[i];
    // 各皿(1, 2, 3貫のカウント)
    REP(i, n)
    c[a[i]]++;

    FOR(c3, 0, n)
    FOR(c2, 0, n)
    FOR(c1, 0, n)
    {
        int s = c1 + c2 + c3;
        if (s == 0)
            continue;
        // 1, 2, 3貫の皿がc1, c2, c3枚であるときを考える
        dp[c1][c2][c3] = 1.0 * n / s;
        if (c1)
            dp[c1][c2][c3] += dp[c1 - 1][c2][c3] * c1 / s;
        if (c2)
            dp[c1][c2][c3] += dp[c1 + 1][c2 - 1][c3] * c2 / s;
        if (c3)
            dp[c1][c2][c3] += dp[c1][c2 + 1][c3 - 1] * c3 / s;
    }

    cout << fixed << setprecision(10) << dp[c[1]][c[2]][c[3]] << "\n";
    return 0;
}
