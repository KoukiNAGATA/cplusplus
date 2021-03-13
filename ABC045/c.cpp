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
using Graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

ll bitPlus(int bit, string s){
    ll ans = 0;
    ll tmp = 0;
    ll l = s.length();
    REP(i, (l-1)){ // 文字列の長さより1桁少ない
        tmp *= 10;
        tmp += s[i] - '0'; // char -> ll
        if (bit & (1 << i)){ // そのbitが1ならば右端から+までを挿入
            ans += tmp;
            tmp = 0;
        }
    }
    // 残った左端の数字を挿入
    tmp *= 10;
    tmp += s.back() - '0'; // char -> ll
    ans += tmp;
    return ans;
}

int main() {
    //cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll ans = 0;
    ll l = s.length();
    //bit full search
    REP(bit, 1 << (l-1)){ // 文字列の長さより1桁少ない符号の組み合わせ
        ans += bitPlus(bit, s);
    }

    cout << ans <<"\n";
	return 0;
}
