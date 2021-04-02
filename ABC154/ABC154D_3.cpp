#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
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
    ll n, k, tmp, ans;
    cin >> n >> k;
    ans = 0;
    vll a(n + 10, 0);
    REP(i, n)
    {
        cin >> a[i];
    }
    tmp = 0;
    REP(i, n)
    {
        tmp += a[i];
        if (i >= k)
        {
            tmp -= a[i - k];
        }
        ans = max(ans, tmp);
    }

    long double out = (ans + k) / 2.0;
    cout << fixed << setprecision(10) << out << "\n";
    return 0;
}
