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
    vector<int> h(MAX + 10);
    vector<int> dp(MAX + 10);
    cin >> n;
    REP(i, n)
    cin >> h[i];

    dp[0] = 0;                //初期値
    dp[1] = abs(h[1] - h[0]); //1つ目は比較なく決まる
    FOR(i, 2, n - 1)          //２つ前から飛ぶ場合と1つ前から飛ぶ場合を比較し続ける
    dp[i] = min(dp[i - 2] + abs(h[i] - h[i - 2]), dp[i - 1] + abs(h[i] - h[i - 1]));

    cout << dp[n - 1] << "\n";
    return 0;
}