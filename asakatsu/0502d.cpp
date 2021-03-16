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

ll GCD(ll x, ll y) {//最大公約数：x%y!=0ならばGCD(y, x%y)、0ならばyを返す(x>y)
    return x % y ? GCD(y, x%y) : y;
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k, g, m;
    cin >> n >> k;
    vll a(n, inf);
    m = 0;
    REP(i, n){
        cin >>a[i];
        if(a[i] > m) m = a[i];
        if(a[i] == k){
            cout << "POSSIBLE" <<"\n";
            return 0;
        }
    }
    g = a[0];
    FOR(i, 1, n-1){
        g = GCD(g, a[i]);
    }
    if(m >= k && k % g == 0){
        cout << "POSSIBLE" <<"\n";
    }else{
        cout << "IMPOSSIBLE" <<"\n";
    }
	return 0;
}