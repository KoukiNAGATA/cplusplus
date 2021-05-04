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
const int MAX = 1000000;
const int MOD = 1000000007;

ll fact[MAX + 10];    //階乗(factorial)
ll invfact[MAX + 10]; //階乗の逆元

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

ll combination(ll A, ll B)
{ //combination(O(1))
    if (A < B)
        return 0;
    if (A < 0 || B < 0)
        return 0;
    return fact[A] * invfact[A - B] % MOD * invfact[B] % MOD;
}

void init()
{
    fact[0] = 1; //0!
    FOR(i, 1, MAX)
    fact[i] = fact[i - 1] * i % MOD; //fact[i] : i!の配列(factorial)

    invfact[MAX] = modpow(fact[MAX], MOD - 2); //フェルマーの小定理よりaの逆元はa^(MOD-2)
    FORR(i, MAX - 1, 0)
    invfact[i] = invfact[i + 1] * (i + 1) % MOD; //(i+1)!の逆元にi+1かけてるだけ
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x, y, n, m;
    cin >> x >> y;
    if ((x + y) % 3 != 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    n = (-1 * x + 2 * y) / 3;
    m = (2 * x + -1 * y) / 3;
    init();
    cout << combination(n + m, n) << "\n";
    return 0;
}