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
    ll n, m, q, ans;
    cin >> n >> m;
    ll ans = 0;
    vll a(n + 1, 0), b(n + 1, 0);
    vvll ma(n + 1, vll(n + 1, 0));
    ll t, x, y;
    REP(i, q)
    {
        cin >> t >> x >> y;
        if (t == 1)
            a[x] = y;
        else
            b[x] = y;
    }

    cout << ans << "\n";
    return 0;
}