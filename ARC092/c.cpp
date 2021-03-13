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

int main(){
    ll n, x, y, ymax, index;
    ll ans = 0;
    cin >> n;
    P r[100], b[100];
    // 赤い点
    REP(i, n){
	    cin >> x >> y;
		r[i] = make_pair(x, y);
    }
    // 青い点
    REP(i, n){
	    cin >> x >> y;
	    b[i] = make_pair(x, y);
    }
    // 昇順ソート（x座標）
    sort(b, b + n);
    //すでにペアが決まっている赤い点にフラグを立てる
    bool c[100] = {};
    // 青い点をx座標が小さい順に見ていく
    REP(i, n){
        ymax = -1;
        REP(j, n){
            // ペアになる赤い点のうちy座標が最大のものを探す
            if(r[j].first < b[i].first && r[j].second < b[i].second && c[j] == 0){
                if(r[j].second > ymax){
                    ymax = r[j].second;
                    index = j;
                }
            }
        }
        // ペアが見つかった場合
        if(ymax > -1){
            c[index] = 1; 
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}