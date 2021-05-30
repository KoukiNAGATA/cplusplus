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
const int INF = 1LL << 30;
const int MAX = 100000;
const int MOD = 1000000007;

// 全探索。0(n^4)。TLE。
int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    int ans = INF;
    cin >> n >> k;
    int mid = k * k / 2 + 1;
    // 入力
    vector<vector<int>> grid(n, vector<int>(n, 0));
    REP(i, n)
    REP(j, n)
    cin >> grid[i][j];

    // 各行について1列ずつずらす。端まで行ったら1行ずらす。
    FOR(i, 0, n - k)
    {
        FOR(j, 0, n - k)
        {
            // 池の値を入力
            vector<int> pond;
            FOR(a, i, i + k - 1)
            FOR(b, j, j + k - 1)
            pond.push_back(grid[a][b]);
            sort(pond.begin(), pond.end(), greater<int>());
            ans = min(ans, pond[mid - 1]);
        }
    }
    cout << ans << '\n';
    return 0;
}
