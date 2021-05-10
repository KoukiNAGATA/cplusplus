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

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    // 200で割った余りで管理
    vll a(n + 10), cnt(210, 0);
    cin >> n;
    ll tmp;
    REP(i, n)
    {
        cin >> tmp;
        a[i] = tmp % 200;
    }

    ll ans = 0;
    // a[j]固定して、j>iでa[j]=a[i]を満たす個数を足す
    REP(i, n)
    {
        ans += cnt[a[i]];
        ++cnt[a[i]];
    }
    cout << ans << "\n";
    return 0;
}