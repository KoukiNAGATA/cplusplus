#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<iomanip>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

ll GCD(ll x, ll y) {
    return x % y ? GCD(y, x%y) : y;
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, tmp;
    cin >> n;
    vll a(n+10, 0);
    REP(i, n-1){
        cin >> tmp;
        a[tmp]++;
    }
    FOR(i, 1, n){
        cout << a[i] << endl;
    }
	return 0;
}