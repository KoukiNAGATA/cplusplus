#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

//DFS...深さ優先探索
vector<bool> seen;
void dfs(const Graph &g, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : g[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(g, next_v); // 再帰的に探索
    }
}

int main() {
    // 頂点数と辺数
    int n, m; 
    cin >> n >> m;

    // グラフ入力受取 (ここでは無向グラフを想定)
    Graph g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // 頂点 0 をスタートとした探索
    seen.assign(n, false); // 全頂点を「未訪問」に初期化
    dfs(g, 0);
}

// // tに辿り着けるかどうか
//     if (seen[t]) cout << "Yes" << endl;
//     else cout << "No" << endl;


// //　連結成分の個数
// for (int v = 0; v < N; ++v) {
//         if (seen[v]) continue; // v が探索済みだったらスルー
//         dfs(G, v); // v が未探索なら v を始点とした DFS を行う
//         ++count;
//     }
//     cout << count << endl;