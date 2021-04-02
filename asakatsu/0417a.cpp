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
    ll n, l, min, ans;
    cin >> n >> l;
    min = inf;
    ans = 0;
    FOR(i, 1, n)
    {
        ans += l + i - 1;
        if (abs(l + i - 1) < abs(min))
        {
            min = l + i - 1;
        }
    }

    cout << ans - min << "\n";
    return 0;
}