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
    ll a, b;
    cin >> a >> b;
    if (a > 0)
    {
        cout << "Positive"
             << "\n";
    }
    else if (b < 0)
    {
        //負の掛け算は特殊。
        if ((abs(b - a) + 1) % 2 == 0)
        { //偶数個の掛け算
            cout << "Positive"
                 << "\n";
        }
        else
        {
            cout << "Negative"
                 << "\n";
        }
    }
    else
    {
        cout << "Zero"
             << "\n";
    }
    return 0;
}