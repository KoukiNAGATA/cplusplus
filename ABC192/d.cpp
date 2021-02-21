#include <bits/stdc++.h>
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
using graph = vector<vector<int>>;

// xをn進数とみなしたときm以下であればtrue
bool check(ll n, string x, ll m){
    ll res = 0;
    for( char c : x ){
        if(res > m / n) return false;
        res = res * n + (c - '0');
    }
    return res <= m;
}
 
int main(){
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);

    string x;
    ll m;
    cin >> x >> m;
    // 1桁=何進数でも1桁
    if(x.size() == 1){
        cout << ((x[0] - '0') <= m) << "\n";
        return 0;
    }
    // dの最大値
    int d = 1;
    for( char c : x ) d = max(d, c-'0');

    // 二分探索(端はひとつ余分に抑える)
    ll l = d, r = m + 1;
    while(r - l > 1){
        ll mid = (r + l) / 2;
        if(check(mid, x, m)) l = mid;
        else r = mid;
    }
    cout << l - d << "\n";
    return 0;
}