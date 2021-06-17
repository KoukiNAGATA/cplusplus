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
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    ll ans = 0;
    cin >> n >> k;
    vector<long long> num(k, 0);
    // nまででkで割ってx余る数の個数
    FOR(i, 1, n) num[i%k] ++;
    REP(a, k){
        ll b = (k - a) % k;
        ll c = (k - a) % k;
        if ((b + c) % k == 0){
            ans += num[a] * num[b] * num[c];
        }
    }
    cout << ans <<"\n";
	return 0;
}