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
    ll a;
    cin >> a;
    switch(a%10){
        case 2:
        case 4:
        case 5:
        case 7:
        case 9:
            puts("hon");
            break;
        case 0:
        case 1:
        case 6:
        case 8:
            puts("pon");
            break;
        case 3:
            puts("bon");
            break;
    }
	return 0;
}