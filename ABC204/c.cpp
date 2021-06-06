// UnionFind
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

//DFS...深さ優先探索
vector<bool> seen;
void dfs(const Graph &g, int v)
{
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : g[v])
    {
        if (seen[next_v])
            continue;   // next_v が探索済だったらスルー
        dfs(g, next_v); // 再帰的に探索
    }
}

int main()
{
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;
    int ans = 0;

    // グラフ入力受取 (有向グラフ)
    Graph g(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }

    // 頂点 0 をスタートとした探索
    REP(i, n)
    {
        seen.assign(n, false); // 全頂点を「未訪問」に初期化
        dfs(g, i);
        REP(j, n)
        if (seen[j])
            ++ans;
    }
    cout << ans << "\n";
    return 0;
}