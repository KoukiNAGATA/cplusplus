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

int n, k, a[110], dp[MAX + 10];

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    REP(i, n)
    cin >> a[i];

    // 遷移後の残り石数を見て、相手が負けるならば勝ちフラグを立てる
    REP(j, k + 1)
    {
        // 勝ちフラグ
        int win = 0, cnt = 0;
        // 山の方が数が多い->操作できる
        REP(i, n)
        if (j - a[i] >= 0)
        {
            cnt++;
            // 遷移後に負けフラグが立っている→勝ち
            if (!dp[j - a[i]])
                win++;
        }
        if (cnt == 0) // 操作できない
            dp[j] = 0;
        else if (0 < win)
            dp[j] = 1;
        else
            dp[j] = 0;
    }

    if (dp[k])
        cout << "First"
             << "\n";
    else
        cout << "Second"
             << "\n";
    return 0;
}