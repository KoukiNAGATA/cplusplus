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

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll h, w, c;
    char tmp;
    cin >> h >> w;
    vvll grid (h, vll(w, 0));
    vvll dp (h, vll(w, inf));

    //初期値を入力
    REP(i, h){
        REP(j, w){
            cin >> tmp;
            grid[i][j] = (tmp == '#')? 1 : 0;//.だけ通れるからtrue
        }
    }
    //初期化
    dp[0][0] = grid[0][0];
    //各点までの最小flip回数をdpで求めていく. 行と列それぞれについて隣り合う#がないか調べて, あればまとめてひっくり返す.
    REP(i, h){
        REP(j, w){
            if (i > 0){
                c = grid[i][j];
				if(grid[i-1][j] == 1) c = 0;//行方向の隣が#ならひっくり返しはない
				dp[i][j] = min(dp[i-1][j] + c, dp[i][j]);
			}
            if (j > 0){
                c = grid[i][j];
				if(grid[i][j-1] == 1) c = 0;//列方向の隣が#ならひっくり返しはない
				dp[i][j] = min(dp[i][j-1] + c, dp[i][j]);
			}
        }
    }

    cout << dp[h-1][w-1] << endl;
	return 0;
}