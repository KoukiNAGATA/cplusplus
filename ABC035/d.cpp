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
    int v;
    ll w;
    edge() {}
    edge(int v, ll w) : v(v), w(w){};
};

using Graph = vector<vector<edge>>;

vll dijkstra(int n, Graph &g, int s)
{
    // 初期化
    vll d(n, INF);
    d[s] = 0;
    // 優先度付きキュー。ヒープ構造のdijkstra。(始点, 距離)
    priority_queue<pair<int, ll>> que;
    que.push(make_pair(s, 0));
    while (!que.empty())
    {
        auto p = que.top();
        que.pop();
        int u = p.first;
        ll dist = -p.second;
        // 探索済み
        if (dist > d[u])
            continue;
        for (edge e : g[u])
        {
            // 重みの更新
            if (d[e.v] > d[u] + e.w)
            {
                d[e.v] = d[u] + e.w;
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
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n, 0);
    // 行きと帰りでわける
    Graph g1(n), g2(n);
    REP(i, n)
    cin >> a[i];
    REP(i, m)
    {
        int a, b, c;
        cin >> a >> b >> c;
        // 0オリジン
        a--;
        b--;
        g1[a].emplace_back(b, c);
        g2[b].emplace_back(a, c);
    }
    // 行き
    auto d1 = dijkstra(n, g1, 0);
    // 帰り
    auto d2 = dijkstra(n, g2, 0);
    ll ans = 0;
    REP(i, n)
    {
        // 所要時間
        ll need = d1[i] + d2[i];
        if (need > t)
            continue;
        // 残り時間 = 滞在時間
        ans = max(ans, (t - need) * a[i]);
    }
    cout << ans << "\n";
    return 0;
}