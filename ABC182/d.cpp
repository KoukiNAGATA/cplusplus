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
    ll ans = 0, tmp = 0;
    vll a(n, 0); //初期化忘れない
    vll s(n, 0); //累積和
    vll m(n, 0); //その回までのsの最大値
    REP(i, n)
    cin >> a[i];
    s[0] = a[0];
    m[0] = a[0];
    FOR(i, 1, n - 1)
    {
        s[i] = s[i - 1] + a[i];
        m[i] = max(s[i], m[i - 1]);
    }
    REP(i, n)
    {
        ans = max(ans, tmp + m[i]);
        tmp += s[i];
    }

    cout << ans << "\n";
    return 0;
}