#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
#include <cstdlib>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int ans = 0;
    int siz;
    string s;
    cin >> s;
    siz = s.size();
    vector<int> dp(siz + 1);
    //累積和で初期化。右端までの余りが0のものを考慮する必要がある。
    dp[siz] = 0;
    int tmp = 1;
    REPR(i, siz)
    { //i桁目から右の2019で割った余りの2019で割った余り
        dp[i] = (dp[i + 1] + (int)(s[i] - '0') * tmp) % 2019;
        tmp *= 10;
        tmp %= 2019;
    }

    vector<int> cnt(2019, 0);
    REP(i, siz + 1)
    { //i桁目から右の2019で割った余りを2019個のバケツに放り込んでいく。一致したらansを足す。
        ans += cnt[dp[i]];
        cnt[dp[i]]++;
    }
    cout << ans << "\n";
    return 0;
}