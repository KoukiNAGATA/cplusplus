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
    int n, m, k, a, b;

    // 入力
    cin >> n >> m >> k;
    UnionFind uf(n);
    //人0〜n-1それぞれについて、友達orブロックの関係にある人の数=あとで引く数
    vector<int> FoB(n, 0);

    REP(i, m)
    { //友達関係、union-findを作る
        cin >> a >> b;
        // 0オリジン
        --a;
        --b;
        FoB[a] += 1;
        FoB[b] += 1;
        uf.unite(a, b);
    }

    REP(i, k)
    { //友達候補ならばブロック関係をFoBに加える。友達とブロックの関係はunion-find除けば同じ。
        cin >> a >> b;
        // 0オリジン
        --a;
        --b;
        if (uf.issame(a, b))
        {
            FoB[a] += 1;
            FoB[b] += 1;
        }
    }

    REP(i, n)
    {                                    //人iの友達候補の人数を出力
        cout << uf.size(i) - FoB[i] - 1; //素集合から友達、ブロック、自分の分を引く
        if (i < n)
            cout << " ";
    }
    return 0;
}