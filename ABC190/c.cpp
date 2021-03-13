#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;
template<class T> void chmax(T& a, T b){
    if(a < b){
        a = b;
    }
}

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, ans;
    ans = 0;
    cin >> n >> m;
    vll a(m), b(m);
    REP(i, m) cin >> a[i] >> b[i];
    ll k;
    cin >> k;
    vll c(k), d(k);
    REP(i, k) cin >> c[i] >> d[i];

    // bit full search
    REP(i, 1<<k){
        vll dish(n+1);
        REP(j, k){
            // どっちの皿に乗せるか
            if (i >> j & 1){
                dish[d[j]] ++;
            }else{
                dish[c[j]] ++;
            }
        }

        ll tmp = 0;

        REP(j, m){
            if(dish[a[j]] == 0) continue;
            if(dish[b[j]] == 0) continue;
            tmp++;
        }

        chmax(ans, tmp);
    }

    cout << ans <<"\n";
	return 0;
}