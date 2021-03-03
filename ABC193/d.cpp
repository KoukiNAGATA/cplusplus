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
    ll k;
    cin >> k;
    char tmp;
    vll a, b;
    FOR(i, 2){
        FOR(j, 5){
            cin >> tmp;
            if(j < 4){
                if(i == 0) a.push_back(tmp);
                if(j == 0) b.push_back(tmp);
            }
        }
    }
    return 0;
}