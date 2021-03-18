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

ll n;
// ペアの二重配列で証言を持つ
vector<vector<P>> v;

bool judge(ll bit) {
    // i 人目の証言を検証する
    for (int i = 0; i < n; ++i) {  
        // i 人目が「不親切」だったら、証言はすべて無意味
        if ( !(bit & (1 << i)) ) continue;

        // 証言の確認
        for (P xy : v[i]) {
            int x = xy.first; // x が
            int y = xy.second; // y = 1: 正直、y = 0: 不親切

            // y = 1 なのに「不親切」だったら矛盾
            if (y == 1 && !(bit & (1 << x))) return false;

            // y = 0 なのに「正直者」だったら矛盾
            if (y == 0 && (bit & (1 << x))) return false;
        }
    }
    return true;
}

int main() {
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    ll ans = 0;
    // 配列の形を決める
    v.resize(n);
    // 証言の入力
    REP(i, n) {
        ll a; cin >> a;
        v[i].resize(a);
        REP(j, a) {
            cin >> v[i][j].first >> v[i][j].second;
            // 0origin
            --v[i][j].first; 
        }
    }

    //bit full search どの人が正しいか全通り調べる
    REP(bit, 1 << n){
        // 矛盾 check
        if (judge(bit)) {
            // bit に含まれる人数を数える
            ll cnt = 0;
            REP(i, n) {
                if (bit & (1 << i)) ++cnt;
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans <<"\n";
	return 0;
}