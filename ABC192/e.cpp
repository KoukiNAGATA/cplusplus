// dijkstraの基本
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
const ll INF = 1LL << 60;

struct edge
{
    // 行き先
    int v;
    // 時間
    int t;
    // 出発時間
    int k;
    edge() {}
    edge(int v, int k, int t) : v(v), t(t), k(k){};
};

using Graph = vector<vector<edge>>;

vll dijkstra(int n, Graph &g, int x, int y)
{
    // 初期化
    vll d(n, INF);
    d[x] = 0;
    vector<int> vis(n, 0);
    // 優先度付きキュー。ヒープ構造のdijkstra。(始点, 距離)
    priority_queue<pair<int, ll>> que;
    que.push(make_pair(x, 0));
    while (!que.empty())
    {
        auto p = que.top();
        que.pop();
        int u = p.first;
        ll cst = -p.second;
        // 探索済み
        if (u == y)
            return d;
        if (vis[u])
            continue;
        vis[u] = 1;
        for (edge e : g[u])
        {
            // コスト = 出発時間(いちばん近いkの倍数) + 時間
            ll cst2 = (cst + e.k - 1) / e.k * e.k + e.t;
            // 重みの更新
            if (d[e.v] > cst2)
            {
                d[e.v] = cst2;
                que.push(make_pair(e.v, -d[e.v]));
            }
        }
    }
    return d;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    // 0オリジン
    --x;
    --y;
    vector<int> a(n, 0);
    Graph g(n);
    REP(i, n)
    cin >> a[i];
    REP(i, m)
    {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        // 0オリジン
        --a;
        --b;
        // 無向
        g[a].emplace_back(b, t, k);
        g[b].emplace_back(a, t, k);
    }
    // 視点からのdijkstra
    auto d = dijkstra(n, g, x, y);
    cout << d[y] << "\n";
    return 0;
}