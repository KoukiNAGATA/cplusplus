#include <bits/stdc++.h>
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
using Graph = vector<vector<int>>;

int main()
{
    int sx, sy, tx, ty;
    string ans;
    cin >> sx >> sy >> tx >> ty;
    int dx = tx - sx, dy = ty - sy;
    REP(i, dy)
    ans += "U";
    REP(i, dx)
    ans += "R";
    REP(i, dy)
    ans += "D";
    REP(i, dx)
    ans += "L";
    ans += "L";
    REP(i, dy + 1)
    ans += "U";
    REP(i, dx + 1)
    ans += "R";
    ans += "DR";
    REP(i, dy + 1)
    ans += "D";
    REP(i, dx + 1)
    ans += "L";
    ans += "U";
    cout << ans << "\n";
}