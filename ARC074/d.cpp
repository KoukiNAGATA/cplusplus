// priority_que 累積和
#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const int MAX = 100000;
const ll INF = 1LL << 60;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 全体の入力
    int n;
    cin >> n;
    vll a(3 * n);
    REP(i, 3 * n)
    cin >> a[i];

    // 前から前処理. nケを選んだ和の最大値を累積和で. 1オリジン
    vll s(2 * n + 1, 0);
    // 昇順
    priority_queue<ll, vll, greater<ll>> que1;
    REP(i, n)
    {
        s[i + 1] = s[i] + a[i];
        que1.push(a[i]);
    }
    // n番目から2n-1番目まで
    FOR(i, n, 2 * n - 1)
    {
        // 最小値
        ll mi = que1.top();
        if (a[i] > mi)
        {
            s[i + 1] = s[i] - mi + a[i];
            que1.pop();
            que1.push(a[i]);
        }
        else
            s[i + 1] = s[i];
    }

    // 後ろから前処理. nケを選んだ和の最小値を累積和で. 1オリジン
    vll t(2 * n + 1, 0);
    // 降順
    priority_queue<ll> que2;
    REP(i, n)
    {
        t[i + 1] = t[i] + a[3 * n - 1 - i];
        que2.push(a[3 * n - 1 - i]);
    }
    // 2n-1番目からn番目まで
    FOR(i, n, 2 * n - 1)
    {
        // 最大値
        ll ma = que2.top();
        if (a[3 * n - 1 - i] < ma)
        {
            t[i + 1] = t[i] - ma + a[3 * n - 1 - i];
            que2.pop();
            que2.push(a[3 * n - 1 - i]);
        }
        else
            t[i + 1] = t[i];
    }

    // 集計
    ll ans = INF * -1;
    FOR(i, n, 2 * n)
    ans = max(ans, s[i] - t[3 * n - i]);
    cout << ans << endl;
}