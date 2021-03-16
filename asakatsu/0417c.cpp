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
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll r, g, b, n, ans, tmp;
    cin >> r >> g >> b >> n;
    ans = 0;
    FOR(i, 0, n){//iケのRの箱を選ぶ
        FOR(j, 0, n){//jケのGの箱を選ぶ
            tmp = n - r*i - g*j;
            if(tmp >= 0 && tmp % b == 0) ans ++;
        }
    }

    cout << ans << endl;
	return 0;
}