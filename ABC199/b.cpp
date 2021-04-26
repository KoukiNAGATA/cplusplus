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
    ll n, xmin, xmax;
    xmin = 0;
    xmax = MAX;
    cin >> n;
    vll a(n, 0), b(n, 0);
    REP(i, n)
    cin >> a[i];
    REP(i, n)
    cin >> b[i];
    REP(i, n)
    {
        xmin = max(a[i], xmin);
        xmax = min(b[i], xmax);
    }
    if (xmax < xmin)
    {
        cout << 0 << "\n";
        return 0;
    }
    cout << xmax - xmin + 1 << "\n";
    return 0;
}