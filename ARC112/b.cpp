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
using Graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

int main()
{
    ll b, c, ans;
    ans = 0;
    cin >> b >> c;

    if (b == 0)
    {
        if (c < 2)
        {
            cout << 1 << "\n";
            return 0;
        }
        else
        {
            ans = c;
        }
    }
    else if (b > 0)
    { // b > 0
        if (c < 3)
        {
            cout << c + 1 << "\n";
            return 0;
        }
        else
        {
            if (2 * b - c > 0)
            {
                ans = 3 + (c - 2) * 2;
            }
            else
            {
                ans = (c - 2) + (2 * b + 1);
            }
        }
    }
    else
    { // b < 0
        if (c < 3)
        {
            cout << c + 1 << "\n";
            return 0;
        }
        else
        {
            if (-2 * (-b) + 1 - c > 0)
            {
                ans = 3 + (c - 2) * 2;
            }
            else
            {
                ans = (c - 1) + (2 * (-b) + 1);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}