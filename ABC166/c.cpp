#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
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
    ll n,m,ans,a,b;
    cin >> n >> m;
    ans = 0;
    vector<P> h(n+1);
    FOR(i,1,n){
        cin >> h[i].first;
        h[i].second = 1;
    }
    REP(i, m){
        cin >> a >> b;
        if(h[a].first < h[b].first){
            h[a].second = 0;
        }else if(h[a].first > h[b].first){
            h[b].second = 0;
        }else{
            h[a].second = 0;
            h[b].second = 0;
        }
    }
    FOR(i,1,n){
        if(h[i].second == 1){
            ans++;
        }
    }
    cout << ans <<"\n";
	return 0;
}