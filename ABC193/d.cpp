#include <bits/stdc++.h>
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
using Graph = vector<vector<int>>;

ll score(string s)
{
    vector<ll> cnt(10);
    // cnt[0] = 0, cnt[1] = 1, ..., cnt[9] = 9
    iota(cnt.begin(), cnt.end(), 0);
    // 見つかった枚数分だけ*10する
    for (char c : s)
        cnt[c - '0'] *= 10;
    // 配列の合計値を求める
    return accumulate(cnt.begin(), cnt.end(), 0);
}
int main()
{
    ll k;
    string s, t;
    cin >> k >> s >> t;
    vector<ll> cnt(10, k);
    for (char c : s + t)
        cnt[c - '0']--;
    ll win = 0;
    // x, yの組について全探索
    FOR(x, 1, 9)
    {
        FOR(y, 1, 9)
        {
            s.back() = '0' + x;
            t.back() = '0' + y;
            if (score(s) <= score(t))
                continue;
            win += cnt[x] * (cnt[y] - (x == y));
        }
    }
    cout << fixed << setprecision(10) << double(win) / ((9 * k - 8) * (9 * k - 9)) << "\n";
}