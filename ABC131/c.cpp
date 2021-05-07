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

long long GCD(long long x, long long y)
{ //最大公約数
    //ユークリッド：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x % y ? GCD(y, x % y) : y;
}

long long LCM(long long x, long long y)
{ //最小公倍数
    return x * y / GCD(x, y);
}

int main()
{
    ll a, b, c, d;
    ll ans = 0;
    cin >> a >> b >> c >> d;
    ans += b - b / c - b / d + b / LCM(c, d);
    ans -= a - 1 - (a - 1) / c - (a - 1) / d + (a - 1) / LCM(c, d);
    cout << ans << "\n";
    return 0;
}