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
using graph = vector<vector<int>>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll V = 0, E = 0;
    FOR(i, 1, n) V += i * (n-i+1);
    REP(i,n-1) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a,b);//1<=L<=uかつv<=R<=nを満たすすべての(L,R)の組について、辺(u,v)がf(L,R)に含まれることを仮定
        E += a * (n-b+1);
    }
    ll ans = V-E;
    cout << ans << endl;
    return 0;
}
