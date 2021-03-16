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
    ll n, ans;
    ans = 0;
    cin >> n;
    vll a;
    for (ll i = 1; i * i <= n-1; i++){//n-1の約数を求める。K>2
        if ((n - 1) % i == 0){
            if (i * i != (n-1)){
                ans += 2;
            }else{
                ans ++;
            }
            if(i == 1) ans --;
        }
    }
    for (ll i = 1; i * i <= n; i++){//nの約数を求める。K>2
        if (n % i == 0){
            a.push_back(i);
            if (i * i != n) a.push_back(n / i);
        }
    }

    for(ll x : a){
        if(x == 1) continue;//1は範囲外
        ll tmp = n;
        while(tmp % x == 0){
            tmp = tmp / x;
        }
        if(tmp % x == 1) ans ++;
    }

    cout << ans << endl;
	return 0;
}