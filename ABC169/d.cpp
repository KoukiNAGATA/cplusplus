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

// 素因数分解
vector<P> prime_factorize(ll n)
{
    // {素数, 割れる回数}のペア
    vector<P> res;
    for (ll p = 2; p * p <= n; ++p)
    {
        if (n % p != 0)
            continue;
        int num = 0;
        while (n % p == 0)
        {
            ++num;
            n /= p;
        }
        res.push_back(make_pair(p, num));
    }
    // nが素数
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    auto pf = prime_factorize(n);
    ll ans = 0;
    for (auto p : pf)
    {
        // その素数で割れる回数から、p^1, p^2, ... でわれるか見る
        ll e = p.second;
        ll cur = 1;
        while (e >= cur)
        {
            e -= cur;
            ++cur;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}