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
const int MAX = 1e9;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, l, k;
    cin >> n >> l >> k;
    vll a(n);
    REP(i, n)
    cin >> a[i];
    // mid以上の長さのピースk個以上に分割することができるかを判定。貪欲で求まる、二分探索。範囲注意。
    ll left = -1, right = MAX + 10;
    while (right - left > 1)
    {
        ll mid = (left + right) / 2;
        ll cnt = 0, pre = 0;
        REP(i, n)
        {
            // 分割した長さがmid以上か、残りがmid以上か
            if (a[i] - pre >= mid && l - a[i] >= mid)
            {
                ++cnt;
                pre = a[i];
            }
        }
        // 分割した個数がk個以上なら更新
        if (cnt >= k)
            left = mid;
        else
            right = mid;
    }
    // leftまではk個以上に分割できる。rightからはできない。
    cout << left << endl;
    return 0;
}