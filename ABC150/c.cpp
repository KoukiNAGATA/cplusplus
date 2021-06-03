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
const int INF = 1 << 30;
const int MAX = 100000;
const int MOD = 1000000007;

int n, p[8], q[8];

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    REP(i, n)
    cin >> p[i];
    REP(i, n)
    cin >> q[i];

    vector<int> v;
    REP(i, n)
    v.push_back(i + 1);
    int idx = 0;
    int a, b;
    do
    {
        // pと完全一致
        bool ok = true;
        REP(i, n)
        {
            if (v[i] != p[i])
                ok = false;
        }
        if (ok)
            a = idx;

        // qと完全一致
        ok = true;
        REP(i, n)
        {
            if (v[i] != q[i])
                ok = false;
        }
        if (ok)
            b = idx;

        ++idx;
    } while (next_permutation(v.begin(), v.end()));

    // 距離をとるだけなので0オリジンでよい
    int ans = abs(a - b);
    cout << ans << endl;
}