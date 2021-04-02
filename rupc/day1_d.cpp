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
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    REP(i, n)
        cin >> a[i];

    // 区間 [j, i) の平均値を前処理で求める
    vector<vector<double>> f(n + 1, vector<double>(n + 1));
    FOR(i, 0, n)
    {
        REP(j, i)
        {
            double sum = 0;
            FOR(k, j, i)
            sum += a[k];
            f[j][i] = sum / (i - j);
        }
    }

    // DP
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, -INF));
    dp[0][0] = 0;
    FOR(i, 0, n)
    {
        REP(j, i)
        {
            FOR(k, 1, m)
            {
                chmax(dp[i][k], dp[j][k - 1] + f[j][i]);
            }
        }
    }

    double res = -INF;
    // mケ以下で何分割が最大か
    FOR(i, 0, m)
    chmax(res, dp[n][i]);
    // 小数点以下の長さを指定
    cout << fixed << setprecision(10) << res << "\n";
}
