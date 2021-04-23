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
    ll n, m, X, Y;
    cin >> n >> m >> X >> Y;
    vll x(n, 0), y(m, 0);
    REP(i, n)
    cin >> x[i];
    REP(i, m)
    cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    X = max(X, x[n - 1]);
    Y = min(Y, y[0]);

    if (X < Y)
        cout << "No War"
             << "\n";
    else
        cout << "War"
             << "\n";
    return 0;
}