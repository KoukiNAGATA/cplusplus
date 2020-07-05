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
    ll n, m, k, ans;
    cin >> n >> m >> k;
    ll curr_k = k;
    ans = 0;
    vll a(n, 0);
    vll b(m, 0);
    ll tmp = 0;

    FOR(i, 1, n){
        cin >> tmp;
        if(i > 1){
            a[i] = a[i-1] + tmp;
        }else{
            a[i] = tmp;
        }
    }
    FOR(i, 1, m){
        cin >> tmp;
        if(i > 1){
            b[i] = b[i-1] + tmp;
        }else{
            b[i] = tmp;
        }
    }

    FOR(i, 1, n){
        FOR(j, 1, m){
            if(a[i] + b[j] <= k){
                ans = max(ans, i + j);
            }
        }
    }

    cout << ans <<"\n";
	return 0;
}