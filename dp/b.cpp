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

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    vector<int> h(MAX + 10);
    vector<int> dp(MAX + 10);

    cin >> n >> k;

    REP(i, n)
    {
        cin >> h[i];
        dp[i] = INF; //一旦無限大で埋めておく
    }

    dp[0] = 0;                //初期値
    dp[1] = abs(h[1] - h[0]); //1つ目は比較なく決まる

    // O(nk)
    FOR(i, 2, n)
    {
        int K = min(i, k);
        FOR(j, 1, K)
        dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    }
    cout << dp[n - 1] << "\n";
    return 0;
}