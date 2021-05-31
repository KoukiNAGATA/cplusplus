// ワーシャルフロイド法。全点対最短経路
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

int dist[310][310];
int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    // 初期化。2つ足してもオーバーフローしないくらい。
    REP(i, n)
    REP(j, n)
    dist[i][j] = INF / 2;

    // 直接接している頂点の重み代入
    REP(i, m)
    {
        int a, b, t;
        cin >> a >> b >> t;
        --a;
        --b;
        dist[a][b] = t;
        dist[b][a] = t;
    }
    // ワーシャルフロイド法。任意の節点kについて、経由したほうがdist[i][j]が縮まるか調べる。O(n^3)
    REP(k, n)
    REP(i, n)
    REP(j, n)
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    // 各点を始点とした最長距離の最小化
    int ans = INF;
    REP(i, n)
    {
        int tmp = 0;
        REP(j, n)
        {
            if (i == j)
                continue;
            tmp = max(tmp, dist[i][j]);
        }
        ans = min(ans, tmp);
    }

    cout << ans << '\n';
    return 0;
}
