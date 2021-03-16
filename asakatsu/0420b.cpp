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
    ll n, m, l, p, q, r, ans;
    ans = 0;
    cin >> n >> m >> l >> p >> q >> r;
    //そのままの向きから傾けていって全探索
    ll tmp = (n/p) * (m/q) * (l/r);
    ans = max(ans, tmp);//同じ型同士で比較する！
    tmp = (n/q) * (m/p) * (l/r);
    ans = max(ans, tmp);
    tmp = (n/r) * (m/q) * (l/p);
    ans = max(ans, tmp);
    tmp = (n/p) * (m/r) * (l/q);
    ans = max(ans, tmp);
    tmp = (n/r) * (m/p) * (l/q);
    ans = max(ans, tmp);
    tmp = (n/q) * (m/r) * (l/p);
    ans = max(ans, tmp);
    cout << ans << endl;
	return 0;
}