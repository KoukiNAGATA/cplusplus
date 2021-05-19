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
    int n;
    cin >> n;
    vector<double> p(3010);
    vector<vector<double>> dp(3010, vector<double>(3010));
    REP(i, n)
    cin >> p[i];

    // 初期化
    dp[0][0] = 1;
    REP(i, n)
    REP(omote, n + 1)
    {
        // i + 1枚中omote枚が表 = (i枚中omote枚が表) * (i + 1枚目が裏) + (i枚中omote - 1枚が表) * (i + 1枚目が表)。n枚中i枚が表のときを考える
        dp[i + 1][omote] += dp[i][omote] * (1 - p[i]);
        dp[i + 1][omote + 1] += dp[i][omote] * p[i];
    }

    double ans = 0;
    // n枚中omote(>n - omote)枚が表
    REP(omote, n + 1)
    if (n - omote < omote)
        ans += dp[n][omote];
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}