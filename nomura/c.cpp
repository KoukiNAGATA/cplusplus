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
using graph = vector<vector<int>>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll ans = 0;
    ll tmp = 1;
    ll prev = 0;//前の段の頂点の数
    vll a(n+1, 0);
    vll sum(n+2, 0);//sum[n+1]を0としてよい
    REP(i, n+1) cin >> a[i];
    REPR(i, n+1) sum[i] = sum[i+1] + a[i];
    REP(i, n+1){
        if(tmp < a[i]){
            cout << -1 << endl;
            return 0;
        }
        ans += tmp;
        tmp -= a[i];
        tmp = min(tmp*2, sum[i+1]);
    }
    cout << ans << endl;
	return 0;
}