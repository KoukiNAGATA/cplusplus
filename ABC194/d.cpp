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
using Graph = vector<vector<int>>;

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
    int n;
    double ans = 0.0;
    cin >> n;

    FOR(i, 1, n-1){
        // 確率pの事象が起きる期待値は1/p回
        double tmp = (double)n / (double)(n - i);
        ans += tmp;
    }

    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}