// 二分探索
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Edge = pair<int, ll>;
const ll INF = 1LL << 60;
const int MAX = 100000;
const int MOD = 1000000007;

// n個中i個を選んでjが作れるか(部分和. ナップサックの亜種)
bool dp[110][MAX + 10];

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力
    int n;
    cin >> n;
    vll h(n), s(n);
    REP(i, n)
    {
        cin >> h[i] >> s[i];
    }
    // 二分探索(ペナルティxが与えられたとき、すべてのペナルティをx以下にできるか)
    ll l = 0, r = INF;
    while (r - l > 1)
    {
        ll mid = (r + l) / 2;
        bool ok = true;
        // ペナルティがmidになるまでの残り時間の配列
        vll t(n, 0);
        REP(i, n)
        {
            if (mid < h[i])
                ok = false; // 元からmidより高い
            else
                t[i] = (mid - h[i]) / s[i];
        }
        // 残り時間が迫ってる順
        sort(t.begin(), t.end());
        // 時刻iに残り時刻t[i]のものを撃つ
        REP(i, n)
        if (t[i] < i)
            ok = false;

        if (ok)
            r = mid;
        else
            l = mid;
    }

    cout << r << "\n";
    return 0;
}