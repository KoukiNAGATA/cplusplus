// 階乗の逆元
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

ll fact[2 * MAX + 10];    //階乗(factorial)
ll invfact[2 * MAX + 10]; //階乗の逆元

ll modpow(ll a, ll n)
{ //二分累乗法により、Nを2の累乗の和に分解してO(logN)で求める
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}

void init()
{ //階乗と逆元のテーブル作成
    fact[0] = 1;
    FOR(i, 1, MAX)
    fact[i] = fact[i - 1] * i % MOD; //fact[i] : i!の配列(factorial)

    invfact[MAX] = modpow(fact[MAX], MOD - 2); //フェルマーの小定理よりaの逆元はa^(MOD-2)
    FORR(i, MAX - 1, 0)
    invfact[i] = invfact[i + 1] * (i + 1) % MOD; //(i+1)!の逆元にi+1かけてるだけ
}

ll combination(ll a, ll b)
{ //aCb(O(1))
    if (a < b)
        return 0;
    if (a < 0 || b < 0)
        return 0;
    return fact[a] * invfact[a - b] % MOD * invfact[b] % MOD;
}

int main()
{
    int w, h;
    cin >> w >> h;
    --w;
    --h;
    init();
    cout << combination(w + h, w) << "\n";
}