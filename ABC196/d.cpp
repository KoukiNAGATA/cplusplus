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

int h, w, a, b, ans = 0;
vector<vector<bool>> used;

// (0, 0), 残りa枚, b枚からdp
void dfs(int i, int j, int a, int b)
{
    // 前処理
    // aまたはbの畳を使い切った
    if (a < 0 || b < 0)
        return;
    // 次の行へ
    if (j >= w)
    {
        j = 0;
        i++;
    }
    // 最後の行まで埋まる→h-1行目ラストの次はh行目。1通り足す
    if (i == h)
    {
        ans++;
        return;
    }
    // 配置済み→次へ
    if (used[i][j])
    {
        dfs(i, j + 1, a, b);
        return;
    }

    // 配置
    used[i][j] = true;
    // b
    dfs(i, j + 1, a, b - 1);
    // aを横に
    if (j + 1 < w and !used[i][j + 1])
    {
        used[i][j + 1] = true;
        dfs(i, j + 1, a - 1, b);
        // 戻しておく
        used[i][j + 1] = false;
    }
    // aを縦に
    if (i + 1 < h and !used[i + 1][j])
    {
        used[i + 1][j] = true;
        dfs(i, j + 1, a - 1, b);
        // 戻しておく
        used[i + 1][j] = false;
    }
    // 戻しておく
    used[i][j] = false;
    return;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w >> a >> b;
    used.resize(h);
    REP(i, h)
    {
        used[i].resize(w);
    }
    dfs(0, 0, a, b);
    cout << ans << "\n";
}