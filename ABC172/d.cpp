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

ll enum_divisors(ll N) {
    ll res = 0;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res ++;
            // 重複しないならば i の相方である N/i も push
            if (N/i != i) res ++;
        }
    }
    return res;
}

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll k, ans;
    cin >> k;
    ans = 1;
    if(k == 1){
        cout << 1 <<"\n";
        return 0;
    }
    FOR(i, 2, k){
        ll tmp = enum_divisors(i);
        ans += tmp * i;
    }

    cout << ans <<"\n";
	return 0;
}