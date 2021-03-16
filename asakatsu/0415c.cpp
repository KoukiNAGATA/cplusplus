#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
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
    ll n, ans, tmp;
    cin >> n;
    vll a(n+1, 0);
    REP(i, n+1){
        cin >> tmp;
        a[i] = tmp;
    }
    sort(a.begin(), a.end());
    ans = a[1] - a[0];//初期化
    REP(i, n){
        ans = GCD(a[i+1] - a[i], ans);
    }
    cout << ans << endl;
	return 0;
}
