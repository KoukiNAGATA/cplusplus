#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using p = pair<int, int>;

int bfs(int)

    int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h, w, c, sx, sy, gx, gy;
    char tmp;
    cin >> h >> w;
    vvll grid(h, vll(w, 0));
    vvll dp(h, vll(w, inf));

    //初期値を入力
    REP(i, h)
    {
        REP(j, w)
        {
            cin >> tmp;
            if (tmp == '#')
            {
                grid[i][j] = 1;
            }
            else if (tmp == '.')
            {
                grid[i][j] = 0;
            }
            else if (tmp == 's')
            {
                grid[i][j] = 0;
                sx = i;
                sy = j;
            }
            else
            {
                grid[i][j] = 0;
                gx = i;
                gy = j;
            }
        }
    }
    //初期化
    dp[0][0] = grid[0][0];
    //0.0から各点までのを経路をdpで求めていく.
    REP(i, h)
    {
        REP(j, w)
        {
            c = (grid[i][j] == 1) ? 1 : 0;
            if (i > 0)
            {
                dp[i][j] = min(dp[i - 1][j] + c, dp[i][j]);
            }
            if (j > 0)
            {
                dp[i][j] = min(dp[i][j - 1] + c, dp[i][j]);
            }
        }
    }
    if (dp[h - 1][w - 1] <= 2)
    {
        cout << "YES"
             << "\n";
    }
    else
    {
        cout << "NO"
             << "\n";
    }
    return 0;
}