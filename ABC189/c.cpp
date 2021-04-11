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
const int MAX = 100000;
const ll INF = 1LL << 60;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, ans;
    cin >> n;
    ans = 0;
    vector<int> a(n, 0);
    // 区間内の最小値. dpの初期化注意する
    vector<vector<int>> dp(n + 10, vector<int>(n + 10, MAX));
    FOR(i, 1, n)
    cin >> a[i];
    // 初期化
    dp[1][1] = a[1];
    FOR(i, 1, n)
    {
        FOR(j, i, n)
        {
            dp[i][j] = min(dp[i][j - 1], a[j]);
            ans = max(ans, dp[i][j] * (j - i + 1));
        }
    }

    cout << ans << "\n";
    return 0;
}