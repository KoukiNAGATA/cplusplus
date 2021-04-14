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
const int MAX = 100000;
const ll INF = 1LL << 60;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, a, b;
    cin >> n;
    // 現在の票数の差を管理
    ll sub = 0;
    // そこで演説した場合に得られる差を管理(x[i] = 2a + b)
    vll x(n, 0);
    ll ans = 0;
    REP(i, n)
    {
        cin >> a >> b;
        sub -= a;
        x[i] = 2 * a + b;
    }
    sort(x.begin(), x.end(), greater<ll>());
    while (sub <= 0)
    {
        sub += x[ans];
        ans++;
    }

    cout << ans << "\n";
    return 0;
}