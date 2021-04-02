#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
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
using p = pair<int, int>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x, y, tmp;
    vll ans(n, 0);
    cin >> n >> x >> y;
    x--;
    y--; //0オリジンに
    //キョリ初期化。
    REP(i, n)
    {
        FOR(j, i + 1, n - 1)
        {
            tmp = min(j - i, abs(x - i) + abs(y - j) + 1);
            ans[tmp]++;
        }
    }
    FOR(i, 1, n - 1)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}