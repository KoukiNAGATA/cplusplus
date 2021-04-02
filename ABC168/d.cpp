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

//最短経路問題はBFSが最適！
int main()
{
    // 頂点数と辺数
    int n, m, a, b;
    cin >> n >> m;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph g(n + 1);
    REP(i, m)
    {
        cin >> a >> b;
        g[a].push_back(b); //aから辿れる頂点の配列
        g[b].push_back(a); //bから辿れる頂点の配列
    }

    // BFSのためのデータ構造
    vector<int> dist(n + 1, -1); // 始点からの距離。全頂点を「未訪問」に初期化。
    vector<int> pre(n + 1, -1);  // 始点に向かう一つ先の点。
    queue<int> que;              //始点に近い順に訪問していくのでqueue。

    // 初期条件 (頂点1を初期ノードとする)
    dist[1] = 0;
    que.push(1);

    // BFS開始 (キューが空になるまで探索を行う)
    while (!que.empty())
    {
        // キューから先頭頂点を取り出す
        int v = que.front();
        que.pop();
        // vから辿れる頂点をすべて調べる
        for (int nv : g[v])
        {
            if (dist[nv] != -1)
                continue; // すでに発見済みの頂点は探索しない
            // 新たな頂点nvについて距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            pre[nv] = v;
            que.push(nv);
        }
    }

    cout << "Yes"
         << "\n";
    FOR(i, 2, n)
        cout << pre[i] << "\n";
    return 0;
}