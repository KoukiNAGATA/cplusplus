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
    ll n, m, k;
    ll ans = 0;
    cin >> n >> m >> k;
    vll A, B;
    ll tmp;
    REP(i, n){
        cin >> tmp;
        A.push_back(tmp);
    }
    REP(i, m){
        cin >> tmp;
        B.push_back(tmp);
    }
    // i冊目まで読んだ場合の合計時間の配列
    vll a, b;
    a.push_back(0);
    b.push_back(0);
    REP(i, n){
        a.push_back(a[i] + A[i]);
    }
    REP(i, m){
        b.push_back(b[i] + B[i]);
    }
    // aをi冊読んだ場合bを何冊読めるか. O(N+M)
    ll j = m;
    REP(i, n + 1){
        if (a[i] > k) break;
        while (b[j] > k - a[i]) --j;
        ans = max(ans, i + j);
    }
    cout << ans <<"\n";
	return 0;
}