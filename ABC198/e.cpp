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
struct Edge
{
    int to;
    int cost;
};
using Graph = vector<Edge>;
using P = pair<long, int>;
const ll INF = 1LL << 60;
const int MAX = 100000;

/* dijkstra(G,s,dis,prev)
    入力：グラフ G, 開始点 s, 距離を格納する dis, 最短経路の前の点を記録するprev
    計算量：O(|E|log|V|)
    副作用：dis, prevが書き換えられる
*/
void dijkstra(const Graph &G, int s, vector<int> &dis, vector<int> &prev)
{
    int N = G.size();
    dis.resize(N, MAX);
    prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first)
        {
            continue;
        }
        for (auto &e : G[v])
        {
            if (dis[e.to] > dis[v] + e.cost)
            {
                dis[e.to] = dis[v] + e.cost;
                prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
}

/* get_path(prev, t)
    入力：dijkstra で得た prev, ゴール t
    出力： t への最短路のパス
*/
vector<int> get_path(const vector<int> &prev, int t)
{
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur])
    {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 頂点数と辺数
    int n;
    cin >> n;
    vector<int> c(n, 0);
    FOR(i, 1, n)
    cin >> c[i];
    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph g(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a++;
        b++;
        g[a].push_back(Edge(b, 1));
        g[b].push_back(Edge(a, 1));
    }

    vector<int> dis;
    vector<int> prev;
    // 頂点 1 をスタートとした探索
    dijkstra(g, 1, dis, prev);
    // check
    FOR(i, 1, n)
    {
        bool flag = false;
        for (auto p : get_path(prev, i))
        {
            // 同じ色か
            if (p == i)
                continue;
            if (c[p] == c[i])
                flag = true;
        }
        if (!flag)
            cout << i << "\n";
    }
    return 0;
}