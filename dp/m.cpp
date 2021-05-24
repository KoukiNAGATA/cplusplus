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

int n, k;
int a[110];

// iまでの人にj個配ったときの組み合わせ。1オリジン
int dp[110][100010];

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    // 0オリジン
    REP(i, n)
    cin >> a[i];

    // 0人に0こ配る組み合わせは1
    dp[0][0] = 1;
    // iを固定して累積和
    REP(i, n)
    {
        // iまで配ったときの累積和を取る。1オリジン
        int sum[100010];
        sum[0] = 0;
        // iまでにk個以下配った組み合わせの累積和
        FOR(j, 0, k)
        sum[j + 1] = (sum[j] + dp[i][j]) % MOD;

        // 累積和を用いてi+1までの組み合わせを求める
        FOR(j, 0, k)
        // 負の MOD に気を付ける(法を足して正にしてからmod)、i+1に0からmax(j, a[i])個配る
        dp[i + 1][j] = (sum[j + 1] - sum[max(0, j - a[i])] + MOD) % MOD;
    }

    cout << dp[n][k] << '\n';

    return 0;
}