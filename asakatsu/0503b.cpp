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
    ll n, m, ans;
    cin >> n >> m;
    //ペアの配列
    vector<P> students(n+1);
    vector<P> points(m+1);
    FOR(i, 1, n) cin >> students[i].first >> students[i].second;
    FOR(i, 1, m) cin >> points[i].first >> points[i].second;
    FOR(i, 1, n){
        ll mi = inf;
        ll ans = -1;
        FOR(j, 1, m){
            ll tmp = abs(students[i].first-points[j].first) + abs(students[i].second-points[j].second);
            if(tmp < mi){
                mi = tmp;
                ans = j;
            }
        }
        cout << ans <<"\n";
    }
	return 0;
}