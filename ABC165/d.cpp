#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iomanip>
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
    ll a, b, n, ans;
    cin >> a >> b >> n;
    ans = 0;
    if(b > n){
        ans = (a*n)/b - a*(n/b);
        cout << ans <<"\n";
        return 0;
    }
    //bの倍数を超えない最大のnを求める
    ll tmp = n % b + 1;
    tmp = n - tmp;
    ans = (a*tmp)/b - a*(tmp/b);
    cout << ans <<"\n";
	return 0;
}