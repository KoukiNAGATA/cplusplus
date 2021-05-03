// クラスカル法。最小全域木
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
const ll INF = 1LL << 60;
const int MAX = 100000;
const int MOD = 1000000007;

// 辺e = (u, v)を{w(e), {u, v}}で表す
using Edge = pair<int, pair<int, int>>;

struct UnionFind
{
    vector<int> par, siz;
    UnionFind(int n) : par(n, -1), siz(n, 1) {} // 連結成分サイズの配列。最初はみんな根、サイズ1。

    // 木の根を求める
    int root(int x)
    {
        if (par[x] < 0)
            return x; // 根
        else
            return root(par[x]); // 経路圧縮(O(logn)になる)
    }

    // xとyの属する集合を併合。小さい方をくっつける。
    bool unite(int x, int y)
    {
        // 先に経路圧縮。根どうしを結合する。
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y); // sizの大きい方を根に
        par[y] = x;     //yの根はxに。葉はrootの値が正になる。
        siz[x] += siz[y];
        return true;
    }

    //xとyが同じ集合に属するか判定
    bool issame(int x, int y) { return root(x) == root(y); }

    //集合のサイズを返す
    int size(int x) { return siz[root(x)]; }
};

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    // 辺集合
    vector<Edge> edges(m);
    ll ans = 0;
    REP(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u, v));
    }

    // 辺の重み(第一要素)昇順ソート
    sort(edges.begin(), edges.end());

    // クラスカル法
    UnionFind uf(n);
    for (auto &e : edges)
    {
        int w = e.first;
        int u = e.second.first;
        int v = e.second.second;

        // 既に連結→サイクルが形成されるので追加しない
        if (uf.issame(u, v))
            continue;

        // 辺(u, v)を追加
        ans += w;
        uf.unite(u, v);
    }

    cout << ans << "\n";
    return 0;
}