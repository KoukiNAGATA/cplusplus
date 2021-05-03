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
    int n, m, s, c, ans;

    cin >> n >> m;
    vector<int> a(n, -1);

    REP(i, m)
    {
        cin >> s >> c;
        // 桁数0オリジン
        --s;
        if (a[s] == -1 || a[s] == c) // 元々値が入っていないor元々入っている値が同じ
            a[s] = c;
        else // 同じ桁に別条件→条件を満たさない
        {
            cout << -1 << "\n";
            return 0;
        }
    }

    if (n == 3)
    { //n==3
        // 先頭が0
        if (a[0] == 0)
        {
            cout << -1 << "\n";
            return 0;
        }

        // 未定義は0に
        if (a[0] == -1)
            a[0] = 1; //3ケタで最小の数字は100番代
        if (a[1] == -1)
            a[1] = 0;
        if (a[2] == -1)
            a[2] = 0;

        ans = a[0] * 100 + a[1] * 10 + a[2];
        cout << ans << "\n";
        return 0;
    }
    else if (n == 2)
    { //n==2。必ず2ケタ
        // 先頭が0
        if (a[0] == 0)
        {
            cout << -1 << "\n";
            return 0;
        }

        // 未定義は0に
        if (a[0] == -1) //2ケタで最小の数字は10番代
            a[0] = 1;
        if (a[1] == -1)
            a[1] = 0;
        ans = a[0] * 10 + a[1];
        cout << ans << "\n";
        return 0;
    }
    else
    { //n==1。必ず1ケタ
        // 未定義は0に
        if (a[0] == -1)
            a[0] = 0;
        ans = a[0];
        cout << ans << "\n";
        return 0;
    }
}
