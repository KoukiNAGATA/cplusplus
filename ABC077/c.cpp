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
using Grid = vector<vector<bool>>;

// lower_boundとupper_boundの練習
int main() {
    ll n, ans;
    ans = 0;
    cin >> n;

    vll a(n, 0);
    vll b(n, 0);
    vll c(n, 0);

    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    REP(i, n) cin >> b[i];
    sort(b.begin(), b.end());
    REP(i, n) cin >> c[i];
    sort(c.begin(), c.end());


    REP(i, n){ // 真ん中のb固定で考える
        auto itr_a = lower_bound(a.begin(), a.end(), b[i]) - a.begin(); // b[i]以上で最小のaの添字=b[i]以下のaの個数
        auto itr_c = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
        ll cnt_c = c.size() - itr_c;
        ans += itr_a * cnt_c;
    }

	cout << ans << endl;
	return 0;
}