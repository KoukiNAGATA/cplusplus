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
    ll n, ans;
    cin >> n;
    ans = 0;
    vll a(n+1, 0);
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n){
        if(a[a[i]] == i) ans ++;
    }
    cout << ans/2 <<"\n";
	return 0;
}
