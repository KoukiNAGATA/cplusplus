#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, a, p, x; 
    cin >> n;
    ll ans = inf;
    REP(i, n){
        cin >> a >> p >> x;
        if(x - a > 0){
            ans = min(ans, p);
        }
    }
    if(ans == inf){
        cout << -1 <<"\n";
        return 0;
    }

    cout << ans <<"\n";
	return 0;
}