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
const int INF = 1LL << 30;
const int MAX = 100000;
const int MOD = 1000000007;

// 距離を管理するリスト
vector<vector<int>> disList(100010, vector<int>());

// 親を見てu一致すればtrue, 一致しなければ更に親を見る
bool isConclude(vector<int> f, int v, int u)
{
    if (f[v] == u)
        return true;
    else if (v == 1) //行き止まり
        return false;
    else
        return isConclude(f, f[v], u);
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力。1オリジン
    int n, q, tmp, u, d;
    cin >> n;
    // 逆向きグラフfと順向きグラフg(親から生えている方を順)
    Graph g(n + 1);
    vector<int> f(n + 1);
    FOR(i, 2, n)
    {
        cin >> tmp;
        f[i] = tmp;
        g[tmp].push_back(i);
    }
    // 距離を埋めるのにbfs
    vector<int> dist(n + 1, -1); // 始点からの距離。全頂点を「未訪問」に初期化。
    queue<int> que;              //始点に近い順に訪問していくのでqueue。

    // 初期条件 (頂点1を初期ノードとする)
    dist[1] = 0;
    que.push(1);

    // BFS開始 (キューが空になるまで探索を行う)
    while (!que.empty())
    {
        // キューから先頭頂点を取り出す
        int v = que.front();
        que.pop();

        // vから辿れる頂点をすべて調べる
        for (auto nv : g[v])
        {
            if (dist[nv] != -1)
                continue; // すでに発見済みの頂点は探索しない

            // 新たな頂点nvについて距離情報を更新してキューに追加する
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }

    // 頂点->距離のリストから、距離->頂点のリストを作成
    FOR(i, 1, n)
    disList[dist[i]].push_back(i);

    // クエリ処理
    cin >> q;
    REP(i, q)
    {
        int ans = 0;
        cin >> u >> d;
        // 距離がdの頂点リストvを探索し、親を見てuがあれば+1
        for (int v : disList[d])
        {
            if (v == u) // 自身がuの例外
            {
                ++ans;
                continue;
            }
            if (isConclude(f, v, u))
                ++ans;
        }
        cout << ans << "\n";
    }
    return 0;
}