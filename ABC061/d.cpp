#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define INF 1LL << 60
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

template <class T>
bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

using Edge = pair<int, long long>;
int n, m;
vector<vector<Edge>> G;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    G.resize(n);
    REP(i, m)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        --a, --b;                    // 0 origin
        G[a].push_back(Edge(b, -w)); // 重みを負に
    }

    vector<long long> dist(n, INF);
    bool negative = false;
    dist[0] = 0;
    for (int iter = 0; iter <= n * 2; ++iter)
    {
        REP(i, n)
        {
            if (dist[i] >= INF / 2)
                continue;
            for (auto e : G[i])
            {
                if (chmin(dist[e.first], dist[i] + e.second))
                {
                    if (e.first == n - 1 && iter == n * 2)
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