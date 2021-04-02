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
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

template <class T>
void chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
    }
}

template <class T>
void chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
    }
}

// 入力
int n, m;
Graph g; // グラフ

// メモ化再帰
int dp[100100];
int rec(int v)
{
    if (dp[v] != -1)
        return dp[v]; // 既に更新済み

    int res = 0;
    // 生えてる頂点について再帰
    for (auto nv : g[v])
    {
        chmax(res, rec(nv) + 1);
    }
    return dp[v] = res; // メモしながらリターン
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g.resize(n);
    int ans = 0;
    REP(i, m)
    {
        int x, y;
        cin >> x >> y;
        --x, --y; // 0-indexed にする
        g[x].push_back(y);
    }

    // 初期化
    REP(i, n)
    dp[i] = -1;

    // 全ノードを一通り更新しながら答えを求める;
    REP(i, n)
    chmax(ans, rec(i));
    cout << ans << "\n";
    return 0;
}