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
    ll n, ans, tmp;
    cin >> n;
    ans = 1;
    tmp = 2;
    string s;
    REP(i, n)
    {
        cin >> s;

        if (s == "OR")
            ans += tmp;
        tmp *= 2;
    }
    cout << ans << "\n";
    return 0;
}