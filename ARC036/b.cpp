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
const int MAX = 300000;
const int MOD = 1000000007;

int n, k;
int a[MAX + 10], front[MAX + 10], ba[MAX + 10];

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n)
    cin >> a[i];
    int ans = 0;
    // 右の山の方が大きいか
    REP(i, n - 1)
    if (a[i] < a[i + 1])
        front[i + 1] = front[i] + 1;
    // 左の山の方が大きいか
    FORR(i, n - 1, 1)
    if (a[i] < a[i - 1])
        ba[i - 1] = ba[i] + 1;
    REP(i, n)
    ans = max(ans, front[i] + ba[i] + 1);
    cout << ans << endl;
    return 0;
}
