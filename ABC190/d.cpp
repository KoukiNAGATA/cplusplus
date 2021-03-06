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
    ll n;
    cin >> n;
    // (A+B)(B−A+1)=2NとなるNを求める。Nを2で割り切れなくなるまで割る。
    while (n % 2 == 0)
        n /= 2;
    ll sq = sqrt(n), ans = 0;
    //nの約数列挙((x, y)のペア重複含む)
    for (ll i = 1; i <= sq; i++)
        if (n % i == 0)
            ans += 2;
    // (x, y)=(y, x)
    if (sq * sq == n)
        ans--;
    // *2(どっちがxy=2N(xyは偶奇不一致)の偶数部分になるか)
    cout << ans * 2 << "\n";
}