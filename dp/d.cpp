// ナップサック問題
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
const ll INF = 1LL << 60;
const int MAX = 100000;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll W; //下のwと重複してしまうので大文字
    vll w(110), v(110);
    cin >> n >> W;
    FOR(i, 1, n)
    cin >> w[i] >> v[i];
    vvll dp(110, vll(100010));

    FOR(i, 0, n)
    { //荷物i番目までで上限jのときの最大値を求める。O(nW)。荷物0ケの場合がある。
        FOR(j, 0, W)
        {                         //荷物の重さ上限を上げていく
            if (i == 0 || j == 0) //初期値。荷物0個の場合と、重さ0の場合は0
                dp[i][j] = 0;
            else if (w[i] <= j) // w[i]が入るキャパがある→ギリギリ入るナップサックに荷物を入れて比較する
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    //荷物n番目までで上限Wのときの最大値
    cout << dp[n][W] << "\n";
    return 0;
}
