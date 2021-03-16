#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    string x; 
    cin >> x;
    int stack = 0;
    int cnt = 0;
    int length = (int)x.size();
    // ペアになっていない"("をstackに詰めていく。
    REP(i, length) {
        if (x[i] == 'S') ++stack;
        else if (stack > 0) --stack, ++cnt;
    }
    cout << length - cnt*2 << endl;
    return 0;
}