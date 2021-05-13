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
const int MAX = 200000;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    // 距離を測る
    int r = r2 - r1, c = c2 - c1;
    int ans = 3;
    // 完全一致
    if (!r && !c)
        ans = 0;
    // 1マス
    else if (r == c || r == -c || abs(r) + abs(c) <= 3)
        ans = 1;
    // 2マス
    else if ((r ^ c ^ 1) & 1 || abs(r + c) <= 3 || abs(r - c) <= 3 || abs(r) + abs(c) <= 6)
        ans = 2;
    cout << ans << endl;
}