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

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll x, k, d;
    cin >> x >> k >> d;
    // 一般化
    x = abs(x);
    // まずなるべく原点に近づく
    ll straight = min(k, x / d);
    k -= straight;
    x -= straight * d;
    // 残り回数は偶数ならそのまま、奇数なら負の方向にd
    if (k % 2 == 0)
        cout << x << "\n";
    else
        cout << d - x << "\n";
    return 0;
}