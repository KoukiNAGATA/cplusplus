// 二部グラフ、ツリー上のDFS
#include <bits/stdc++.h>
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

// 重み付き無向グラフ
using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

Graph g;
vector<int> ans;

// v を c に塗る。p は v の根
void dfs(int v, int p, int c)
{
    ans[v] = c;
    for (auto e : g[v])
    {
        // 枝刈り
        if (e.first == p)
            continue;
        // 重みが奇数→別の色に塗る
        if (e.second & 1)
            dfs(e.first, v, 1 - c);
        else
            dfs(e.first, v, c);
    }
}

int main()
{
    int n;
    cin >> n;
    g.assign(n, vector<Edge>());
    // 辺の入力
    REP(i, n - 1)
    {
        int u, v, w;
        cin >> u >> v >> w;
        // 無向グラフ 0オリジン
        --u, --v;
        g[u].push_back(Edge(v, w));
        g[v].push_back(Edge(u, w));
    }
    // dfs 根を0として、色0で塗っておく
    ans.assign(n, 0);
    dfs(0, -1, 0);
    for (auto v : ans)
        cout << v << endl;
}