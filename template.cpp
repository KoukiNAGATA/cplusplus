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
using graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const int MAX = 100000;
const ll INF = 1LL << 60;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, ans;
    cin >> a >> b;
    ans = 0;
    vll dp(a + 10, INF); //初期化忘れない

    cout << ans << "\n";
    return 0;
}