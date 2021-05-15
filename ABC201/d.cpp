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

int game_count(int a, int b, Graph &grid, Graph &dp, Graph &flag)
{                   //そのマスからゴールまでの高橋くんの最大値を返す。メモ化再帰
    if (flag[a][b]) // 訪問済み
        return dp[a][b];
    int res;
    if (a == h && b == w) //終了条件
        return dp[a][b] = 0;
    if ((a + b) % 2 == 0) // 高橋くんの番
    {
        if (a == h) // 右にのみいける
            res = game_count(a, b + 1, grid, dp, flag) + grid[a][b + 1];
        else if (b == w) // 下にのみいける
            res = game_count(a + 1, b, grid, dp, flag) + grid[a + 1][b];
        else
            res = max(game_count(a + 1, b, grid, dp, flag) + grid[a + 1][b], game_count(a, b + 1, grid, dp, flag) + grid[a][b + 1]);
    }
    else // 青木くんの番→青木くんが最適になるように動く
    {
        if (a == h) // 右にのみいける
            res = game_count(a, b + 1, grid, dp, flag) - grid[a][b + 1];
        else if (b == w) // 下にのみいける
            res = game_count(a + 1, b, grid, dp, flag) - grid[a + 1][b];
        else
            res = min(game_count(a + 1, b, grid, dp, flag) - grid[a + 1][b], game_count(a, b + 1, grid, dp, flag) - grid[a][b + 1]);
    }
    // 訪問
    flag[a][b] = 1;
    return dp[a][b] = res;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力。1オリジン
    cin >> h >> w;
    Graph grid(h + 1, vector<int>(w + 1));
    // メモ化再帰
    Graph dp(h + 1, vector<int>(w + 1, INF));
    Graph flag(h + 1, vector<int>(w + 1, 0));
    //初期値を入力
    char tmp;
    FOR(i, 1, h)
    {
        FOR(j, 1, w)
        {
            cin >> tmp;
            (tmp == '-') ? grid[i][j] = -1 : grid[i][j] = 1; //-はfalse, +はtrue
        }
    }

    int cnt = 0;
    cnt = game_count(1, 1, grid, dp, flag);

    string ans;
    if (cnt > 0)
        ans = "Takahashi";
    else if (cnt == 0)
        ans = "Draw";
    else
        ans = "Aoki";
    cout << ans << "\n";
    return 0;
}