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
const ll INF = 1LL << 60;

const int MAX = 200000;
const int MOD = 1000000007;

// 素因数分解した配列の取得
vector<P> prime_factorize(ll n)
{
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
        // pでnum回割れる
        res.push_back(make_pair(p, num));
    }
    // 素数
    if (n != 1)
        res.push_back(make_pair(n, 1));
    return res;
}

ll modpow(ll A, ll N)
{ //二分累乗法により、Nを2の累乗の和に分解してO(logN)で求める
    ll res = 1;
    while (N > 0)
    {
        if (N & 1)
            res = res * A % MOD;
        A = A * A % MOD;
        N >>= 1;
    }
    return res;
}

// 逆元を累積で持っておく
ll fact[MAX], invfact[MAX];
void COMinit()
{
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;

    FOR(i, 2, MAX)
    fact[i] = fact[i - 1] * i % MOD;

    invfact[MAX] = modpow(fact[MAX], MOD - 2); //フェルマーの小定理よりaの逆元はa^(MOD-2)
    FORR(i, MAX - 1, 0)
    invfact[i] = invfact[i + 1] * (i + 1) % MOD; //(i+1)!の逆元にi+1かけてるだけ
}
ll COM(int n, int k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    //nCr = n!/k!/(n-k)! = fact[n] * invfact[k] * invfact[n - k]
    return fact[n] * (invfact[k] * invfact[n - k] % MOD) % MOD;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    COMinit();
    cin >> n >> m;
    auto vec = prime_factorize(m);
    ll ans = 1;
    // 各素因数pについて
    for (auto p : vec)
    {
        int b = p.second;
        // nHb
        ll tmp = COM(b + n - 1, b);
        ans = (ans * tmp) % MOD;
    }
    cout << ans << "\n";
    return 0;
}