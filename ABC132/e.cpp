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

int n, m;
Graph g;
int s, t, u, v;

ll solve()
{
    // n頂点*3状態
    vector<vector<ll>> dist(n, vector<ll>(3, -1));
    // 初期化
    dist[s][0] = 0;
    queue<P> que;
    que.push({s, 0});
    // BFS
    while (!que.empty())
    {
        P cur = que.front();
        que.pop();
        // 頂点番号
        int v = cur.first;
        // 状態
        int parity = cur.second;
        // 探索
        for (auto nv : g[v])
        {
            // 次の状態
            int np = (parity + 1) % 3;
            // 未探索
            if (dist[nv][np] == -1)
            {
                dist[nv][np] = dist[v][parity] + 1;
                que.push({nv, np});
            }
        }
    }
    if (dist[t][0] == -1)
        return -1;
    else
        return dist[t][0] / 3;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g.resize(n);
    // グラフの入力
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        --u, --v; // 0 origin
        g[u].push_back(v);
    }
    cin >> s >> t;
    --s, --t; // 0 origin
    cout << solve() << "\n";
}