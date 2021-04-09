#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
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

ll GCD(ll a, ll b)
{ //最大公約数
    //ユークリッド：x%b!=0ならばGCD(b, a%b)、0ならばyを返す(a>b)
    return a % b ? GCD(b, a % b) : b;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    vll x(n);
    REP(i, n)
    cin >> x[i];

    ll ans = INF;
    for (int bit = 1; bit < (1 << 15); bit++)
    {
        ll t = 1;
        FOR(i, 0, 15)
        if ((bit >> i) & 1)
            t *= p[i];

        bool ok = true;
        REP(i, n)
        if (GCD(t, x[i]) == 1)
            ok = false;

        if (ok)
            ans = min(ans, t);
    }

    cout << ans << "\n";
    return 0;
}