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

int main() {
    ll n, ans;
    ans = 0;
    cin >> n;
    vll l(n, 0);
    vll r(n, 0);
    REP(i, n){
        cin >> l[i] >> r[i];
    }


    // n case
    REP(i, n){
        ans = 0;
        ll tmp = r[i] - 2 * l[i];
        if(tmp < 0){
            cout << 0 << endl;
            continue;
        }
        cout << (tmp+1)*(tmp+2)/2 << endl;
    }

	return 0;
}