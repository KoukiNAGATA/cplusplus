#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 200000
#define inf 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力
    double sx, sy, gx, gy;
    cin >> sx >> sy >> gx >> gy;
    // SからGまでをSy:Gyに内分する点
    double ans = (double)(sx * gy + gx * sy) / (sy + gy);
    // 小数
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}