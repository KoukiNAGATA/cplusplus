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
    ll n, a_min, sum;
    cin >> n;
    sum = 0;
    vll a(n, 0);//初期化忘れない
    REP(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    if(a.size() % 2 == 0){
        FORR(i, n-1, n/2){
            sum += a[i] * 2;
        }
        sum -= a[n-1];
    }else{
        FORR(i, n-1, (n-1)/2){
            sum += a[i] * 2;
        }
        sum -= a[n-1];
        sum -= a[(n-1)/2];
    }

    cout << sum <<"\n";
	return 0;
}