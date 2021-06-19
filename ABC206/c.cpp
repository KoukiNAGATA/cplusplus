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
const int MAX = 1e9;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    map<ll, ll> cnt; //単語がキー
    ll n;
    cin >> n;
    ll a;
    REP(i, n)
    {
        cin >> a;
        cnt[a]++;
    }
    ll ans = 0;
    ll i = 0;
    for (const auto &x : cnt)
    {
        i += x.second;
        ans += x.second * (n - i);
    }
    cout << ans << "\n";
    return 0;
}