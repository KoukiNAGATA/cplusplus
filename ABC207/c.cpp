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
    int n;
    cin >> n;
    vector<double> l(n), r(n);
    // input
    REP(i, n)
    {
        // 閉区間に直す
        int t;
        cin >> t >> l[i] >> r[i];
        if (t == 2)
            r[i] -= 0.1;
        else if (t == 3)
            l[i] += 0.1;
        else if (t == 4)
        {
            r[i] -= 0.1;
            l[i] += 0.1;
        }
    }
    // 共通部分を持つか全探索
    int ans = 0;
    REP(i, n)
    FOR(j, i + 1, n - 1) // 左の大きい方と右の小さい方が交差すればよい
    ans += (max(l[i], l[j]) <= min(r[i], r[j]));

    cout << ans << "\n";
    return 0;
}