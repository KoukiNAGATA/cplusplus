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

ll n, m, x, ans;

void isSkill(ll bit, vvll a){//この組の理解度を算出
    bool flag = true;
    vll now(m+1, 0);
    ll money = 0;
    REP(i, n){
        if (bit & 1 << i){//  そのbitが1ならば
            FOR(j, 1, m) now[j] += a[i][j];
            money += a[i][0];
        }
    }
    FOR(i, 1, m){//今回の組がいけているか判断
        if (now[i] < x){
            flag = false;
            break;
        }
    }
    if(flag) ans = min(ans, money);
    return;
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    ans = inf;
    vvll a(n+1, vll(m+1, 0));
    //input
    REP(i, n) REP(j, m+1) cin >> a[i][j];
    //bit full search
    REP(bit, 1 << n){
        isSkill(bit, a);
    }

    if(ans == inf) ans = -1;
    cout << ans <<"\n";
	return 0;
}