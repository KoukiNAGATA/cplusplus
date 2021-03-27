// UnionFindの実用
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

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
    ll n, m;
    cin >> n >> m;
    vector<ll> ans(m + 10, 0);
    vector<pair<int, int>> g(m);
    REP(i, m)
    {
        cin >> g[i].first >> g[i].second;
        // 0 origin
        --g[i].first, --g[i].second;
    }

    UnionFind uf(n);          // 初期化
    ll res = n * (n - 1) / 2; // 全崩落
    REPR(i, m)
    { // 後ろの辺から連結していく
        ans[i + 1] = res;
        int a = g[i].first, b = g[i].second;
        if (!uf.issame(a, b))
        {
            res -= uf.size(a) * uf.size(b);
            uf.unite(a, b);
        }
    }
    FOR(i, 1, m)
    {
        cout << ans[i] << endl;
    }
}