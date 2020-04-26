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

ll n, m;
//g...各頂点からの有向辺を記録する配列. d...各頂点の最長路を保持する配列.計算量下げる.
vvll g(MAX);
vll d(MAX, 0);
 
ll dfs(ll x){
    if(d[x] > 0) return d[x];
	ll mx = 0;
	REP(i, g[x].size()){//dfsの最大値+1
		mx = max(mx, dfs(g[x][i]) + 1);
	}
    d[x] = mx;
	return mx;
}
 
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	cin >> n >> m;
    ll ans = 0;

	REP(i, m){
		int x, y;
		cin >> x >> y;
        //0オリジンに
		x--;
		y--;
		g[x].push_back(y);
	}

	REP(i, n){//各頂点に対してdp. メモによって計算量を下げる.
		if(d[i] == 0) ans = max(ans, dfs(i));
	}
 
	cout << ans << endl;
}