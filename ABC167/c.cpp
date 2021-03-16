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

ll n, m, x, ans;

void isSkill(vll tmp, vvll a) {//今回の組の計算
    bool flag = true;
    vll now(m+1, 0);
    ll money = 0;
    for(ll num : tmp){//今回の組の理解度を算出
        FOR(i, 1, m){
            now[i] += a[num][i];
        }
        money += a[num][0];
    }
    FOR(i, 1, m){//今回の組がいけているか判断
        if (now[i] < x){
            flag = false;
            break;
        }
    }
    if(flag) ans = min(ans, money);

    while (tmp.back() < n) {
        tmp.back()++;//後ろの値を1大きくした場合
        isSkill(tmp, a);
        tmp.back()--;//後ろに1大きい値を入れた場合
        tmp.push_back(tmp.back()+1);
        isSkill(tmp, a);
    }
    return;
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> x;
    ans = inf;
    vvll a(n+1, vll(m+1, 0));
    FOR(i, 1, n){
        REP(j, m+1){
            cin >> a[i][j];
        }
    }
    vll t = {1};
    isSkill(t, a);
    if(ans == inf){
        ans = -1;
    }

    cout << ans <<"\n";
	return 0;
}