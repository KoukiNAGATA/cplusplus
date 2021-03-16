#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;
template<class T> void chmax(T& a, T b){
    if(a < b){
        a = b;
    }
}

ll modpow(ll A, ll N, ll mod){ // 二分累乗法により、Nを2の累乗の和に分解してO(logN)で求める
    ll res = 1;
    while(N > 0) {
        if(N & 1) res = res * A % mod;
        A = A * A % mod;
        N >>= 1;
    }
    return res;
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c;
    cin >> a >> b >> c;
    b = modpow(b % 4, c, 4);
    cout << modpow(a % 10, b + 4, 10) <<"\n"; // b = 0 のときは4とする
	return 0;
}