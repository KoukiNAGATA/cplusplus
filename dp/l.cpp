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
template <class T>
void chmin(T &a, T b)
{
    if (a > b)
        a = b;
}
template <class T>
void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}

int n;
ll a[3010];
int vis[3010][3010];
ll memo[3010][3010]; // 0になる可能性がある -> 配列visで更新チェック

// メモ化DP
ll dp(int l, int r)
{
    if (l > r)
        return 0;
    // 枝刈り
    if (vis[l][r])
        return memo[l][r];
    vis[l][r] = 1;

    // 今回の番目
    int diff = n - (r - l + 1);
    ll res;
    if (diff % 2 == 0)
    {
        // X-Yを最大化したい
        res = -INF;
        chmax(res, dp(l + 1, r) + a[l]);
        chmax(res, dp(l, r - 1) + a[r]);
    }
    else
    {
        // X-Yを最小化したい
        res = INF;
        chmin(res, dp(l + 1, r) - a[l]);
        chmin(res, dp(l, r - 1) - a[r]);
    }

    return memo[l][r] = res;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n)
    cin >> a[i];

    cout << dp(0, n - 1) << "\n";
    return 0;
}