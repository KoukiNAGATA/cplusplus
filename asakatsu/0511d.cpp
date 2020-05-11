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
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vll write(m, 0);//書き込みがあった
    vll isWrite(n+1, 0);//その掲示板に後に書き込みがあったか
    vll ans;
    REP(i, m){
        cin >> write[i];
    }
    REPR(i, m){
        if(isWrite[write[i]] == 0){
            isWrite[write[i]] = 1;
            ans.push_back(write[i]);
        }
    }
    FOR(i, 1, n){
        if(isWrite[i] == 0){
            ans.push_back(i);
        }
    }
    
    REP(i, n){
        cout << ans[i] <<"\n";
    }
	return 0;
}