// 部分和
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

// n個中i個を選んでjが作れるか(部分和. ナップサックの亜種)
bool dp[110][MAX + 10];

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力
    int n;
    cin >> n;
    vector<int> t(n);
    int sum = 0;
    REP(i, n)
    {
        cin >> t[i];
        sum += t[i];
    }
    // ソート
    sort(t.begin(), t.end());

    dp[0][0] = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= MAX; ++j)
        {
            // i個で作れるならi+1個でも作れる
            dp[i + 1][j] |= dp[i][j];
            // t[i]を選んだ場合に作れる数
            if (j >= t[i])
                dp[i + 1][j] |= dp[i][j - t[i]];
        }
    }
    // n番目までのmin
    int ans = INF;
    REP(i, MAX)
    {
        // iがつくれる
        if (dp[n][i])
        {
            ans = min(ans, max(sum - i, i));
        }
    }
    cout << ans << "\n";
    return 0;
}