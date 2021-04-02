#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <iomanip>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using p = pair<int, int>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k, n, ans, m;
    cin >> k >> n;
    vll a(n, 0);
    REP(i, n)
    {
        cin >> a[i];
    }
    //初期化
    ans = 0;
    m = 0;
    FOR(i, 1, n - 1)
    {
        ans += a[i] - a[i - 1];
        m = max(a[i] - a[i - 1], m);
    }
    //端を加える
    ans += (k - a[n - 1]) + a[0];
    m = max((k - a[n - 1]) + a[0], m);
    ans -= m;

    cout << ans << "\n";
    return 0;
}