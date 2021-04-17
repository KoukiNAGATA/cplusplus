#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
using namespace std;
using ll = unsigned long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const int MAX = 100000;
const ll INF = 1LL << 60;
const ll mod = 1e9 + 7;

ll modpow(ll A, ll N)
{ //二分累乗法により、Nを2の累乗の和に分解してO(logN)で求める
    ll res = 1;
    while (N > 0)
    {
        if (N & 1)
            res = res * A % mod;
        A = A * A % mod;
        N >>= 1;
    }
    return res;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, p, ans;
    cin >> n >> p;
    ans = p - 1;
    if (p == 2 && n == 1)
    {
        cout << ans << "\n";
        return 0;
    }
    if (p == 2)
    {
        cout << 0 << "\n";
        return 0;
    }
    ans = ans * modpow(p - 2, n - 1) % mod;

    cout << ans << "\n";
    return 0;
}