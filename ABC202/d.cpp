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
    int a, b;
    ll k;
    cin >> a >> b >> k;
    // aがiケ, bがjケとなる文字列の層数をdpで数える(i+j格子の最短経路の総数)
    vvll dp(a + 1, vll(b + 1));
    dp[0][0] = 1;
    FOR(i, 0, a)
    {
        FOR(j, 0, b)
        {
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
        }
    }
    // 先頭から決めていく
    while (a > 0 and b > 0)
    {

        if (k <= dp[a - 1][b]) // k <= 先頭がaの個数
        {
            cout << 'a';
            --a;
        }
        else
        {
            k -= dp[a - 1][b]; // 先頭がaの個数分引く
            cout << 'b';
            --b;
        }
    }
    cout << string(a, 'a');
    cout << string(b, 'b');
    cout << '\n';
    return 0;
}
