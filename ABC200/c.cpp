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

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n + 10);
    // 200で割った余りで管理。無闇にll使わない。
    vector<int> cnt(210, 0);
    REP(i, n)
    cin >> a[i];

    // a[j]固定して、j>iでa[j]=a[i]を満たす個数を足す
    ll ans = 0;
    REP(i, n)
    {
        int mo = a[i] % 200;
        ans += cnt[mo];
        cnt[mo]++;
    }
    cout << ans << "\n";
    return 0;
}