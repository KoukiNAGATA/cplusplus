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
const int MAX = 100000;
const int MOD = 1000000007;

ll GCD(ll x, ll y)
{ //最大公約数
    //ユークリッド：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x % y ? GCD(y, x % y) : y;
}

ll LCM(ll x, ll y)
{ //最小公倍数
    return x * y / GCD(x, y);
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a, b;
    int ans = 1;
    cin >> a >> b;

    ll gcd = GCD(a, b);
    //GCDの約数のなかで素数であるものを探す
    if (gcd > 1)
    {
        for (ll i = 2; i * i <= gcd; i++)
        {
            if (gcd % i == 0)
            {
                ans++;
                while (gcd % i == 0)
                { // その素数で割り切れなくなるまで割っていく
                    gcd /= i;
                }
            }
        }
    }

    // gcdが素数
    if (gcd > 1)
        ans++;

    cout << ans << "\n";
    return 0;
}