// Ford-Fulkerson。最大フロー。二部マッチング。
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
const ll INF = 1LL << 30;
const int MAX = 100000;
const int MOD = 1000000007;

struct Edge
{
    // to:行き先、cap:容量、rev:逆辺がG[to]の中で何番目か
    int to, cap, rev;

    Edge(int t, int c, int r)
    {
        to = t;
        cap = c;
        rev = r;
    }
};

vector<Edge> G[105];
bool used[105];

// 辺の追加。G[from]を先に追加したことに注意
void add_edge(int from, int to, int cap)
{
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size() - 1));
}

// 深さ優先探索
int dfs(int s, int t, int f)
{
    // ゴール
    if (s == t)
        return f;

    used[s] = true;
    for (auto &e : G[s])
    {
        if (!used[e.to] && e.cap > 0)
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    int f = -1;
    while (f != 0)
    {
        memset(used, 0, sizeof(used));
        f = dfs(s, t, INF);
        flow += f;
    }
    return flow;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 人数、マーク数、辺数
    int n, g, e;
    cin >> n >> g >> e;

    // マークの入力
    vector<int> p(g);
    REP(i, g)
    cin >> p[i];

    // グラフの入力。重みなし無向→容量1の有向辺
    REP(i, e)
    {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
    }

    // マーク先と定義したゴールを結ぶ
    REP(i, g)
    add_edge(p[i], n + 1, 1);

    // 始点と終点を追加して最大フローに帰着
    int s = 0, t = n + 1;
    cout << max_flow(s, t) << "\n";
    return 0;
}