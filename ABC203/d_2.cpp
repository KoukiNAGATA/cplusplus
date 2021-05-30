// 二次元累積和。中央値の最小値。
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
const int INF = 1 << 30;
const int MAX = 100000;
const int MOD = 1000000007;

// 二次元累積和
struct Ruisekiwa2D
{
    int vh, vw;
    using T = int;
    vector<vector<T>> v;
    Ruisekiwa2D(int w, int h) { init(w, h); }
    // 初期化
    void init(int w, int h)
    {
        vh = h;
        vw = w;
        v.clear();
        v.resize(h, vector<T>(w));
        REP(y, vh)
        REP(x, vw)
        v[y][x] = 0;
    }
    // 代入
    void set(int x, int y, T c) { v[y][x] = c; }
    // 追加
    void add(int x, int y, T c) { v[y][x] += c; }
    // 累積和を構成
    void build()
    {
        REP(y, vh)
        REP(x, vw)
        {
            if (0 < y)
                v[y][x] += v[y - 1][x];
            if (0 < x)
                v[y][x] += v[y][x - 1];
            if (0 < y && 0 < x)
                v[y][x] -= v[y - 1][x - 1];
        }
    }
    // [tx,ty]-[sx,sy]の区間の累積和
    T get(int sx, int tx, int sy, int ty)
    {
        if (tx < sx || ty < sy)
            return 0;
        T rs = v[ty][tx];
        if (0 < sx)
            rs -= v[ty][sx - 1];
        if (0 < sy)
            rs -= v[sy - 1][tx];
        if (0 < sx && 0 < sy)
            rs += v[sy - 1][sx - 1];
        return rs;
    }
};

int n, k, mid, a[810][810];

int check(int lim)
{
    Ruisekiwa2D r2d(n, n);
    // lim以上の値は1に
    REP(y, n)
    REP(x, n)
    if (lim <= a[y][x])
        r2d.add(x, y, 1);
    // 二次元累積和を構成
    r2d.build();

    REP(y, n - k + 1)
    REP(x, n - k + 1)
    {
        // 区間和を取得
        int tot = r2d.get(x, x + k - 1, y, y + k - 1);
        if (tot < mid) // 中央値がlimより小さい
            return false;
    }
    // 中央値がすべての区画でlim以上->もっと大きな値もイケる
    return true;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    mid = k * k / 2 + 1;
    REP(i, n)
    REP(j, n)
    cin >> a[i][j];

    // 二分探索
    int ok = 0, ng = INF;
    while (ok + 1 != ng)
    {
        int md = (ok + ng) / 2;
        if (check(md))
            ok = md;
        else
            ng = md;
    }
    cout << ok << '\n';
    return 0;
}
