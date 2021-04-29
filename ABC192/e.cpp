// 始点から終点へのdijkstra
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
const int MAX = 100000;
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}

// 昇順priority_que
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

struct edge
{
    // 行き先
    int to;
    // 時間
    ll t;
    // 出発時間
    ll k;
    edge() {}
    edge(int to, ll t, ll k) : to(to), t(t), k(k){};
};

using Graph = vector<vector<edge>>;

vll dijkstra(int n, Graph &g, int x, int y)
{
    // 初期化
    vll d(n, INF);
    d[x] = 0;
    // 優先度付きキュー。ヒープ構造のdijkstra。(始点, 距離)
    min_priority_queue<pair<int, ll>> que;
    que.push(make_pair(x, 0));
    while (!que.empty())
    {
        auto p = que.top();
        que.pop();
        int u = p.first;
        ll cst = p.second;
        // 枝刈り
        if (u == y)
            return d;
        if (cst > d[u])
            continue;
        for (auto &e : g[u])
        {
            // コスト = 出発時間(いちばん近い次のkの倍数) + 時間
            ll cst2 = (cst + e.k - 1) / e.k * e.k + e.t;
            // 重みの更新
            if (chmin(d[e.to], cst2))
                que.push(make_pair(e.to, d[e.to]));
        }
    }
    // 未探索
    if (d[y] == INF)
        d[y] = -1;
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
    Graph g(n);
    REP(i, m)
    {
        ll a, b, t, k;
        cin >> a >> b >> t >> k;
        // 0オリジン
        --a;
        --b;
        // 無向
        g[a].emplace_back(b, t, k);
        g[b].emplace_back(a, t, k);
    }
    // 始点から終点へのdijkstra
    auto d = dijkstra(n, g, x, y);
    cout << d[y] << "\n";
    return 0;
}