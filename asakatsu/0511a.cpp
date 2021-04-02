#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vll a(n, 0);
    REP(i, n)
        cin >> a[i];
    ll sum = a[0] + a[1];
    FOR(i, 2, n - 1)
    {
        if (i > 2)
            sum -= a[i - 3];
        sum += a[i];
        if (sum < k)
        {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    return 0;
}