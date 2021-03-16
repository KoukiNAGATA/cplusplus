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
    ll n, k, ans;
    ans = 0;
    cin >> n >> k;
    vll h(n, 0);
    REP(i, n)cin >> h[i];
    while(n > k-1){//1とk-1つを毎回選んで1にする
        n -= k-1;
        ans++;
    }
    if(n > 1) ans ++;//端数
    cout << ans <<"\n";
	return 0;
}