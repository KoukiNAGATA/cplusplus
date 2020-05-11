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

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, l, ans, t;
    cin >> n >> l;
    ans = 0;
    vector<vector <char>> a(l, vector <char>(2*n));
    REP(i, l){
        FOR(j, 1, 2*n-1){
            cin >> a[i][j];
        }
    }
    char tmp;
    FOR(i, 1, 2*n-1){
        cin >> tmp;
        if(tmp == 'o') t = i;
    }
    vll goal(2*n);
    for(ll i = 1; i < 2*n; i += 2){
        ll now = i;
        REP(j, l){
            if(a[j][now-1] == '-'){
                now -= 2;
            }else if(a[j][now+1] == '-'){
                now += 2;
            }
        }
        goal[i] = now;
    }
    for(ll i = 1; i < 2*n; i += 2){
        if(goal[i] == t){
            cout << (i+1)/2 <<"\n";
            return 0;
        }
    }
    return 0;
}