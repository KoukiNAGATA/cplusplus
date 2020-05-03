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
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,ans,tmp;
    cin >> n;
    ans = 0;
    vll a(n+1,0);//初期化忘れない
    vll b(n+1,0);
    vll dp(n, 0);
    FOR(i,1,n){
        cin >> tmp;
        a[i] = i+tmp;
        b[i] = i-tmp;
        if(b[i] > 0)dp[b[i]] += 1;
    }

    FOR(i, 1, n){
        if(a[i] < n) ans += dp[a[i]];
    }
    cout << ans <<"\n";
	return 0;
}