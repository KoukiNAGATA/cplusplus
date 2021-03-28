// ベルマンフォード
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
using graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const int MAX = 100000;
const ll INF = 1LL << 60;

bool chmin(ll &a, ll b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    vector<vector<Edge>> g;
    cin >> n >> m;
    g.resize(n);
    REP(i, m)
    {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a, --b; // 0 origin
        g[a].push_back(Edge(b, -w));
    }

    // 各点における重みの配列
    vll dist(n, INF);
    // 負閉路検出フラグ
    bool negative = false;
    dist[0] = 0;
    for (int iter = 0; iter <= n * 2; ++iter)
    { // 2n回回す
        REP(i, n)
        {
            if (dist[i] >= INF / 2)
                continue;
            for (auto e : g[i])
            { // iから出る各辺について
                if (chmin(dist[e.first], dist[i] + e.second))
                {                                          // 重みの更新
                    if (e.first == n - 1 && iter == n * 2) // 負閉路の検出
                        negative = true;
                }
            }
        }
    }
    if (!negative)
        cout << -dist[n - 1] << endl;
    else
        cout << "inf" << endl;
}