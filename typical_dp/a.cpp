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
using Graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

int main() {
    ll n, ans;
    ans = 0;
    cin >> n;
    ll p[n];
    bool dp[110][11000];// 初期値はfalse
    REP(i, n) cin >> p[i];

    // 初期値を設定
    REP(i, n + 1) dp[i][0] = true;

    // iケ目を足すかどうかで値を埋めていく。
    REP(i, n){
        REP(j, 10000){
            if(dp[i][j]){
                dp[i + 1][j] = true; // 足さない
                dp[i + 1][j + p[i]] = true; // 足す
            }
        }
    }

    REP(i, 10001){
        if(dp[n][i]) ans ++;
    }

	cout << ans << endl;
	return 0;
}