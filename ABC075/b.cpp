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

int h, w;
// 8方向。各方角を定義。
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力。1オリジン
    cin >> h >> w;
    Graph grid(h + 2, vector<int>(w + 2));
    // 入力
    char tmp;
    FOR(i, 0, h + 1)
    {
        FOR(j, 0, w + 1)
        {
            // 端を0で埋める
            if (i == 0 || i == h + 1 || j == 0 || j == w + 1)
            {
                grid[i][j] = 0;
                continue;
            }
            cin >> tmp;
            (tmp == '.') ? grid[i][j] = 0 : grid[i][j] = 1; //.は0, #は1
        }
    }

    // 探索
    FOR(i, 1, h)
    {
        FOR(j, 1, w)
        {
            //爆弾は#、その他は周りの1の個数を出力
            if (grid[i][j])
                cout << "#";
            else
            {
                int ans = 0;
                REP(k, 8)
                if (grid[i + dx[k]][j + dy[k]])
                    ++ans;
                cout << ans;
            }
        }
        // 改行
        cout << "\n";
    }
    return 0;
}