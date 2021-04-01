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
    ll h, w, n, ans;
    cin >> h >> w >> n;
    vvll grid(h, vll(w, 0));
    ans = 0;
    REP(i, n)
    {
        int x, y, a;
        cin >> x >> y >> a;
        if (a == 1)
        {
            REP(i, x)
            {
                REP(j, w)
                {
                    grid[i][j] = 1;
                }
            }
        }
        else if (a == 2)
        {
            FOR(i, x, h - 1)
            {
                REP(j, w)
                {
                    grid[i][j] = 1;
                }
            }
        }
        else if (a == 3)
        {
            REP(i, h)
            {
                REP(j, y)
                {
                    grid[i][j] = 1;
                }
            }
        }
        else
        {
            REP(i, h)
            {
                FOR(j, y, w - 1)
                {
                    grid[i][j] = 1;
                }
            }
        }
    }
    REP(i, h)
    {
        REP(j, w)
        {
            if (grid[i][j] == 0)
                ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}