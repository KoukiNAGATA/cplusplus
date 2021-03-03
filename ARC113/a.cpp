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
using graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;
template<class T> void chmax(T& a, T b){
    if(a < b){
        a = b;
    }
}

int main(){
    ll k; 
    cin >> k;
  
    ll ans = 0;
    FOR(a, 1, k){
        for(ll b = 1; a * b <= k; ++b){
            ans += k / (a * b);
        }
    }
    cout << ans << "\n";
    return 0;
}