#include <bits/stdc++.h>
#define REP(i, n) for(ll i = 0; i < n; i++)
#define REPR(i, n) for(ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define FORR(i, m, n) for(ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n)
#define MAX 100000
#define inf 1000000007
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;


int main() {
    // エラトステネスのふるい
    vector<int> is_prime(MAX, 1);
    is_prime[0] = 0, is_prime[1] = 0;
    for (int i = 2; i < MAX; ++i) {
        if (!is_prime[i]) continue;
        for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    }

    // 2017-like 数かどうか
    vector<int> a(MAX+1, 0);
    REP(i, MAX) {
        if (i % 2 == 0) continue;
        if (is_prime[i] && is_prime[(i+1)/2]) a[i] = 1;
    }

    // 累積和
    vector<int> s(MAX+1, 0);
    REP(i, MAX) s[i+1] = s[i] + a[i];

    // クエリ処理
    int q; 
    cin >> q;
    REP(i, q) {
        int l, r;
        cin >> l >> r;
        ++r;

        cout << s[r] - s[l] << endl;
    }
}