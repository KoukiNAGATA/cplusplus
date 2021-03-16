#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c, ans;
    cin >> a >> b >> c;
    ans = 0;
    ll m = max(a, b);
    m = max(m, c);
    ll s = a + b + c;

    if(m%2 == s%2) ans = (3*m - s)/2;
    else ans = (3*(m+1) - s)/2;

    cout << ans <<"\n";
	return 0;
}