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
using graph = vector<vector<int>>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; 
    cin >> n;
    vll a(n), b(n);
    ll ans = inf;
    REP(i, n){
        cin >> a[i] >> b[i];
    }
    REP(i, n){
        REP(j, n){
            if(i != j){
                ans = min(ans, max(a[i], b[j]));
            }else{
                ans = min(ans, a[i] + b[j]);
            }
        }
    }


    cout << ans <<"\n";
	return 0;
}