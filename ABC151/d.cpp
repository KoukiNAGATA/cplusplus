// 迷路のbfs
#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

// 迷路→縦か横の1マスの移動しかない→右、下、左、上を定義
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// (x, y) を始点とした BFS をして、(x, y) から最も遠いマスへの距離を答える
int bfs(const vector<string> &v, int x, int y)
{
    int h = v.size(), w = v[0].size();
    // 見たものの距離
    vector<vector<int>> dist(h, vector<int>(w, -1));
    // 次に見る
    queue<pair<int, int>> que;

    // 初期化。(x, y)スタート
    int ans = 0;
    que.push(make_pair(x, y));
    dist[x][y] = 0;
    while (!que.empty())
    {
        int x = que.front().first, y = que.front().second;
        ans = max(ans, dist[x][y]);
        que.pop();
        //各方向1マスずつ移動
        for (int dir = 0; dir < 4; ++dir)
        {
            // 移動後の点
            int nx = x + dx[dir], ny = y + dy[dir];
            // 範囲外
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            // 壁
            if (v[nx][ny] == '#')
                continue;
            // 未探索
            if (dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }
    return ans;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> v(h);
    REP(i, h)
    cin >> v[i];

    int ans = 0;
    // 任意の(x, y)からの最長距離を求め、最大値を更新
    REP(x, h)
    {
        REP(y, w)
        {
            if (v[x][y] == '#')
                continue;
            ans = max(ans, bfs(v, x, y));
        }
    }
    cout << ans << endl;
}