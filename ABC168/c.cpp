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
static const double pi = 3.141592653589793;

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    double a, b, h, m, ans;
    cin >> a >> b >> h >> m;
    double x = a*(cos(pi*(h/6+m/360)))-b*(cos(pi*(m/30)));
    double y = a*(sin(pi*(h/6+m/360)))-b*(sin(pi*(m/30)));
    ans = sqrt(x*x + y*y);

    cout << ans <<"\n";
	return 0;
}