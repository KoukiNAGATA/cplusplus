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

//mapの使い方。数え上げ。O(n)
int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    map<string, ll> memo;//
    ll n, maxv;
    maxv = 0;
    cin >> n;
    string tmp;

    REP(i, n){//各単語の登場回数を調べる。
        cin >> tmp;
        memo[tmp] ++;
    }
    
    for (const auto& x : memo) {//登場する最大回数を抑える。
        ll v = x.second;
        if (v > maxv) maxv = v;
    }

    for (auto it = memo.begin(); it != memo.end(); it++) {//最大回数を同じ登場回数のものを出力。
        if (it->second == maxv) {//要素の取り出し
            cout << it->first << endl;
        }
    }
	return 0;
}
