// 迷路のbfs
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

// 迷路→縦か横の1マスの移動しかない→右、下、左、上を定義
const int dc[4] = {1, 0, -1, 0};
const int dr[4] = {0, 1, 0, -1};

// (sx, sy) を始点とした BFS
int bfs(const vector<string> &v, int sx, int sy, int gx, int gy)
{
    int r = v.size(), c = v[0].size();
    // 距離フラグ
    vector<vector<int>> dist(r, vector<int>(c, -1));
    // 次に見る
    queue<pair<int, int>> que;

    // 初期化。(sx, sy)スタート
    que.push(make_pair(sy, sx));
    dist[sy][sx] = 0;
    while (!que.empty())
    {
        int sy = que.front().first, sx = que.front().second;
        que.pop();
        //各方向1マスずつ移動
        for (int dir = 0; dir < 4; ++dir)
        {
            // 移動後の点
            int ny = sy + dr[dir], nx = sx + dc[dir];
            // 範囲外
            if (nx < 0 || ny >= r || ny < 0 || nx >= c)
                continue;
            // 壁
            if (v[ny][nx] == '#')
                continue;
            // 未探索
            if (dist[ny][nx] == -1)
            {
                dist[ny][nx] = dist[sy][sx] + 1;
                que.push(make_pair(ny, nx));
            }
        }
    }
    // ゴールの距離を出力
    return dist[gy][gx];
}

int main()
{
    int r, c;
    cin >> r >> c;
    int sx, sy, gx, gy;
    cin >> sy >> sx >> gy >> gx;
    // 行ごとに入力
    vector<string> v(r);
    REP(i, r)
    cin >> v[i];
    // 任意の(sx, sy)からの最長距離を求め、最大値を更新
    cout << bfs(v, --sx, --sy, --gx, --gy) << "\n";
}