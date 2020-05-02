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

ll n, m, q;
ll ans = 0;
vll a, b, c, d;
 
void dfs(vll A) {//再起全探索
    if (A.size() == n+1) {//(ai, bi, ci, di)の組で与えられるAの添え字は1オリジン
        ll now = 0;
        REP(i,q) {
            if (A[b[i]] - A[a[i]] == c[i]) now += d[i];
        }
        ans = max(ans, now);
        return;
    }
    A.push_back(A.back());//一番後ろに最後尾と同じ値をつける
    while (A.back() <= m) {
        dfs(A);
        A.back()++;
    }
}


int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    a = b = c = d = vll(q);
    REP(i,q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    dfs(vll(1,1));//使わない0番目を埋めて、+1番目は1で考えて十分
    cout << ans <<"\n";
	return 0;
}