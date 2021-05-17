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
const int INF = 1LL << 30;
const int MAX = 100000;
const int MOD = 1000000007;
int h, w;

// メモ化再帰間に合わなかった
int rootCount(int a, int b, Graph &grid, Graph &dp)
{                 //そのマスからゴールまでの組の総和
    if (dp[a][b]) // 訪問済み
        return dp[a][b];
    if (grid[a][b]) // 通れない
        return 0;
    if (a == h && b == w) //終了条件
        return dp[a][b] = 1;
    if (a == h) // 右にのみいける
        return dp[a][b] = rootCount(a, b + 1, grid, dp);
    else if (b == w) // 下にのみいける
        return dp[a][b] = rootCount(a + 1, b, grid, dp);
    else
        return dp[a][b] = (rootCount(a + 1, b, grid, dp) + rootCount(a, b + 1, grid, dp)) % MOD;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力。1オリジン
    cin >> h >> w;
    Graph grid(h + 10, vector<int>(w + 10));
    Graph dp(h + 10, vector<int>(w + 10, 0));
    //初期値を入力
    char tmp;
    FOR(i, 1, h)
    {
        FOR(j, 1, w)
        {
            cin >> tmp;
            (tmp == '.') ? grid[i][j] = 0 : grid[i][j] = 1; //.は通れる -> 0
        }
    }

    // int cnt = rootCount(1, 1, grid, dp);
    dp[1][1] = 1;
    FOR(i, 1, h + 1)
    FOR(j, 1, w + 1)
    {
        if (i < h && !grid[i + 1][j])
        {
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= MOD;
        }
        if (j < w && !grid[i][j + 1])
        {
            dp[i][j + 1] += dp[i][j];
            dp[i][j + 1] %= MOD;
        }
    }
    cout << dp[h][w] << "\n";
    return 0;
}