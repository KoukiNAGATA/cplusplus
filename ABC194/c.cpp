// 重複を考慮しないでカウントするHashSet
#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vll a(n);
    ll ans = 0;
    ll sum = 0;
    REP(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }
    REP(i, n)
    {
        ans += (n - 1) * a[i] * a[i];
    }
    ll tmp = 0;
    REP(i, n)
    {
        tmp += -2 * (sum - a[i]) * a[i];
    }
    tmp /= 2;
    ans = ans + tmp;
    cout << ans << "\n";
}