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
ll GCD(ll x, ll y)
{ //最大公約数：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x % y ? GCD(y, x % y) : y;
}

ll LCM(ll x, ll y)
{                             //最小公倍数
    return x / GCD(x, y) * y; // Be careful not to overflow
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, ans, tmp;
    cin >> n;
    ans = 1;
    REP(i, n)
    {
        cin >> tmp;
        ans = LCM(ans, tmp);
    }

    cout << ans << "\n";
    return 0;
}