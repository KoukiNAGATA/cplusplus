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
const int MAX = 1000000;
const int MOD = 1000000007;

ll cnt[MAX + 10];
int main()
{
    ll n;
    ll ans = 0;
    cin >> n;

    vll a(n + 10, 0);

    REP(i, n)
    {
        cin >> a[i];
        if (a[i] > 0)
            ++cnt[a[i] - 1];
        ++cnt[a[i]];
        ++cnt[a[i] + 1];
    }
    REP(i, MAX + 1)
    if (cnt[i] > ans)
        ans = cnt[i];

    cout << ans << "\n";
    return 0;
}