#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using p = pair<int, int>;
using Grid = vector<vector<bool>>;

void flip(int a, int b, Grid grid, int h, int w, int ans){//右としたの連続する黒目を探してまとめてひっくり返す
    int h1, w1 = 0;
    while(!grid[a+h1][b] && (a + h1 < h)){
        h1 ++;
    }
    while(!grid[a][b+w1] && (b + w1 < w)){
        w1 ++;
    }
    FOR(i, a, a+h1){
        FOR(j, b, b+w1){
            grid[i][j]= !grid[i][j];
        }
    }
    ans ++;
}

int maze_count(int a, int b, Grid grid, int h, int w, int ans){//そのマスからゴールまでにひっくり返した回数を返す
    if(grid[a][b]){//そのマスが通れる
        if(a == h && b == w){//終了条件
            return 0;
        }else if(a == h && b < w){
            maze_count(a, b+1, grid, h, w, ans);
        }else if(a < h && b == w){
            maze_count(a+1, b, grid, h, w, ans);
        }else{
            if(grid[a+1][b] && grid[a][b+1]){
                maze_count(a+1, b+1, grid, h, w, ans);
            }else if(grid[a][b+1]){
                maze_count(a+1, b, grid, h, w, ans);
            }else{
                maze_count(a, b+1, grid, h, w, ans);
            }
        }
    }else{
        flip(a, b, grid, h, w, ans);
        maze_count(a, b, grid, h, w, ans);
    }
    return ans;
}

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    char tmp;
    int ans = 0;
    cin >> h >> w;
    Grid grid(h, vector<bool>(w));

    //初期値を入力
    REP(i, h){
        REP(j, w){
            cin >> tmp;
            (tmp == '#')? grid[i][j] = false : grid[i][j] = true;//.だけ通れるからtrue
        }
    }

    ans = maze_count(0, 0, grid, h, w, ans);
    cout << ans << endl;
	return 0;
}