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
    ll a, b, c, d, e, f, n;
    long double tmp_a, tmp_b;
    cin >> n;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    REP(i, n)
    {
        cin >> tmp_a >> tmp_b;
        if (tmp_a >= 35)
        {
            a++;
        }
        else if (tmp_a >= 30)
        {
            b++;
        }
        else if (tmp_a >= 25)
        {
            c++;
        }
        if (tmp_b >= 25)
        {
            d++;
        }
        else if (tmp_b < 0 && tmp_a >= 0)
        {
            e++;
        }
        else if (tmp_a < 0)
        {
            f++;
        }
    }

    cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << "\n";
    return 0;
}