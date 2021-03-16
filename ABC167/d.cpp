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
    ll n, k, ans;
    cin >> n >> k;
    ans = 0;
    vll a(n+1, 0);//初期化忘れない
    vll flag(n+1, 0);//一度来たかのフラグ。
    FOR(i, 1, n){
        cin >> a[i];
    }

    ll loop = 1;
    while(flag[loop] == 0){//ループ地点を求める=1度来た地点に戻ったらループのスタート地点
        flag[loop] = 1;
        loop = a[loop];
    }

    ll i = 1;
    ll start = 0;
    while(i != loop){//ループ地点までの移動回数
        start++;
        i = a[i];
    }
    
    if(k < start){//ループ地点より前に終わる場合
        ll j = 1;
        while(k > 0){//残り移動回数
            k--;
            j = a[j];
        }
        cout << j <<"\n";
        return 0;
    }

    k -= start;
    ll loopNum = 1;
    i = loop;
    while(a[i] != loop){//ループの移動回数
        loopNum++;
        i = a[i];
    }

    k = k % loopNum;
    i = loop;
    while(k > 0){//残り移動回数
        k--;
        i = a[i];
    }

    ans = i;
    cout << ans <<"\n";
	return 0;
}