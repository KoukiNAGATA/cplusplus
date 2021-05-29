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
const int MAX = 200000;
const ll INF = 1LL << 60;

// 頂点数, カウンター
int n, q, cnt[MAX + 10];
// グラフ
vector<int> e[MAX + 10];

// DFS, いもす法
void dfs(int cu, int pa = -1)
{
    for (auto &to : e[cu])
        if (pa != to) // 逆流を防ぐ
        {
            cnt[to] += cnt[cu];
            dfs(to, cu);
        }
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 頂点数と辺数
    cin >> n >> q;
    int a, b;
    // グラフの入力(木なので辺の本数はn-1本)
    REP(i, n - 1)
    {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    // クエリ処理
    REP(i, q)
    {
        cin >> a >> b;
        cnt[a] += b;
    }
    // いもす法
    dfs(1);
    // count
    FOR(i, 1, n)
    cout << cnt[i] << "\n";
    return 0;
}