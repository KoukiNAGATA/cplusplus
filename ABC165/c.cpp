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
    ll n, m, q, ans;
    cin >> n >> m >> q;
    ans = 0;
    vvll q_in (q, vll(4, 1));
    vll a(n+1, 1);
    REP(i, q){
        cin >> q_in[i][0] >> q_in[i][1] >> q_in[i][2] >> q_in[i][3];
    }
    REP(i, q){//この行の条件を適用するかを決めていく
        ll ans = 0;
        ll change = 0;
        REP(j, i){//手前までの行の和
            if(a[q_in[j][1]] - a[q_in[j][0]]  == q_in[j][2]) ans += q_in[j][3];
        }
        //この行を適用した場合のans。bの値を仮に交換する。
        ll tmp_b = a[q_in[i][1]];
        a[q_in[i][1]] = a[q_in[i][0]] + q_in[i][2];
        REP(j, i+1){//ここまでの行
            if(a[q_in[j][1]] - a[q_in[j][0]]  == q_in[j][2]) change += q_in[j][3];
        }

        if(change < ans){//更新しない場合元に戻す
            a[q_in[i][1]] = tmp_b;
        }
    }

    ans = 0;
    REP(i, q){
        if(a[q_in[i][1]] - a[q_in[i][0]]  == q_in[i][2]) ans += q_in[i][3];
    }
    cout << ans <<"\n";
	return 0;
}