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
const int MAX = 100000;
const ll INF = 1LL << 60;

// 頂点数, 頂点の色, 遷移における色の数
int n, c[100010], cnt[100010];
// グラフ
vector<int> e[100010];
// いい頂点
bool good[100010];

// DFS, cnt[color]...色colorがこれまでの遷移に何回あったか, cu...current, pa...past(初期値=-1)
void dfs(int cu, int pa = -1)
{
    // いい点
    if (cnt[c[cu]] == 0)
        good[cu] = true;
    // 現在の色を通過
    cnt[c[cu]]++;

    for (auto &to : e[cu])
        if (to != pa) // 同じ点に戻らない(木構造なので端点で止まる)
            dfs(to, cu);
    // 頂点から離れる(現在見ている頂点から始点（頂点1）までの情報に限定)
    cnt[c[cu]]--;
    return;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 頂点数と辺数
    cin >> n;
    // 色の入力
    FOR(i, 1, n)
    cin >> c[i];
    // グラフの入力(木なので辺の本数はn-1本)
    REP(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    // 頂点1からDFS
    dfs(1);
    // check
    FOR(i, 1, n)
    if (good[i])
        cout << i << "\n";
    return 0;
}