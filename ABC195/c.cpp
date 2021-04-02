// 重複を考慮しないでカウントするHashSet
#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
#define mod 10000000000000007
using namespace std;
using ll = int64_t;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

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
    ll n;
    ll ans = 0;
    cin >> n;
    if (n / modpow(10, 3) >= 10)
    { //もっと大きい
        ans += (modpow(10, 4) - modpow(10, 3));
        if (n / modpow(10, 4) >= 10)
        {
            ans += (modpow(10, 5) - modpow(10, 4));
            if (n / modpow(10, 5) >= 10)
            {
                ans += (modpow(10, 6) - modpow(10, 5));
                if (n / modpow(10, 6) >= 10)
                {
                    ans += (modpow(10, 7) - modpow(10, 6)) * 2;
                    if (n / modpow(10, 7) >= 10)
                    {
                        ans += (modpow(10, 8) - modpow(10, 7)) * 2;
                        if (n / modpow(10, 8) >= 10)
                        {
                            ans += (modpow(10, 9) - modpow(10, 8)) * 2;
                            if (n / modpow(10, 9) >= 10)
                            {
                                ans += (modpow(10, 10) - modpow(10, 9)) * 3;
                                if (n / modpow(10, 10) >= 10)
                                {
                                    ans += (modpow(10, 11) - modpow(10, 10)) * 3;
                                    if (n / modpow(10, 11) >= 10)
                                    {
                                        ans += (modpow(10, 12) - modpow(10, 11)) * 3;
                                        if (n / modpow(10, 12) >= 10)
                                        {
                                            ans += (modpow(10, 13) - modpow(10, 12)) * 4;
                                            if (n / modpow(10, 13) >= 10)
                                            {
                                                ans += (modpow(10, 14) - modpow(10, 13)) * 4;
                                                if (n / modpow(10, 14) >= 10)
                                                {
                                                    ans += (modpow(10, 15) - modpow(10, 14)) * 4;
                                                    if (n / modpow(10, 15) >= 10)
                                                    {
                                                        ans += (modpow(10, 16) - modpow(10, 15)) * 5;
                                                    }
                                                    else
                                                        ans += (n - modpow(10, 15) + 1) * 5;
                                                }
                                                else
                                                    ans += (n - modpow(10, 14) + 1) * 4;
                                            }
                                            else
                                                ans += (n - modpow(10, 13) + 1) * 4;
                                        }
                                        else
                                            ans += (n - modpow(10, 12) + 1) * 4;
                                    }
                                    else
                                        ans += (n - modpow(10, 11) + 1) * 3;
                                }
                                else
                                    ans += (n - modpow(10, 10) + 1) * 3;
                            }
                            else
                                ans += (n - modpow(10, 9) + 1) * 3;
                        }
                        else
                            ans += (n - modpow(10, 8) + 1) * 2;
                    }
                    else
                        ans += (n - modpow(10, 7) + 1) * 2;
                }
                else
                    ans += (n - modpow(10, 6) + 1) * 2;
            }
            else
                ans += (n - modpow(10, 5) + 1);
        }
        else
            ans += (n - modpow(10, 4) + 1);
    }
    else if (n / modpow(10, 3) < 10 && n / modpow(10, 3) >= 1)
    { // 1000以上
        ans += (n - modpow(10, 3) + 1);
    }
    cout << ans << "\n";
}