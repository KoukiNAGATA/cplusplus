#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

bool isPrime(ll num) //素数かどうかを判定する。
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

    long double sqrtNum = sqrt(num);
    for (ll i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    ll ans = 1;
    cin >> n;
    // 素因数で割れる回数
    vector<ll> num(n + 1, 0);
    // 素数のリスト
    vector<ll> prime;
    FOR(i, 1, n)
    {
        if (isPrime(i))
            prime.push_back(i);
    }
    // iを素因数分解してnumに格納
    FOR(i, 1, n)
    {
        ll tmp = i;
        for (auto x : prime)
        {
            while (tmp % x == 0)
            { // iがxで割り切れる
                num[x]++;
                tmp /= x;
            }
        }
    }
    FOR(i, 1, n)
    ans = (ans % mod * (num[i] + 1)) % mod;
    cout << ans << "\n";
    return 0;
}