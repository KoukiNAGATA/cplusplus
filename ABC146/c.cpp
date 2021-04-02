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

ll a, b, x;
bool check(ll n)
{
    if (a * n + b * to_string(n).size() <= x)
        return true;
    else
        return false;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> x;
    ll l = 0, r = 1e9 + 1;
    // 二分探索
    while (r - l > 1)
    {
        ll mid = (r + l) / 2;
        if (check(mid)) // 買える
            l = mid;
        else // 買えない
            r = mid;
    }
    cout << l << "\n";
    return 0;
}