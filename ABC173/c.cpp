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
using graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

bool isRight(int bit, int h, int w, int k, Grid grid){
    bool is = false;
    int cnt = 0;
    Grid tmpg = grid;
    FOR(i, 1, h){
        if (bit & 1 << i-1){//  そのbitが1ならばi行を塗る
            FOR(j, 1, w) tmpg[i][j] = false;
        }
    }
    FOR(i, 1, w){
        if (bit & 1 << i+h-1){//  そのbitが1ならばj列を塗る
            FOR(j, 1, h) tmpg[j][i] = false;
        }
    }
    FOR(i, 1, h){
        FOR(j, 1, w){
            if(tmpg[i][j] == true) cnt ++;
        }
    }
    if(cnt == k) is = true;
    return is;
}

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w, k;
    char tmp;
    int ans = 0;
    cin >> h >> w >> k;
    Grid grid(h+1, vector<bool>(w+1));

    //初期値を入力
    FOR(i, 1, h){
        FOR(j, 1, w){
            cin >> tmp;
            (tmp == '#')? grid[i][j] = true : grid[i][j] = false;
        }
    }

    //bit full search
    REP(bit, 1 << h+w){
        if(isRight(bit, h, w, k, grid)) ans ++;
    }

    cout << ans <<"\n";
	return 0;
}