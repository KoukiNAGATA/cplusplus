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
using Graph = vector<vector<int>>;

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, tmp;
    cin >> n;
    vll a(MAX, 0);
    FOR(i, 1, 100){
        FOR(j, 1, 100){
            FOR(k, 1, 100){
                tmp = i*i + j*j + k*k + i*j + j*k + k*i;
                a[tmp] ++;
            }
        }
    }
    FOR(i, 1, n) cout << a[i] <<"\n";
	return 0;
}