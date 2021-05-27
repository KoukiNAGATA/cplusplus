// 順列はnext_permutation
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
const int MAX = 1000000;
const int MOD = 1000000007;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    // 入力
    int n, x, y;
    cin >> n;
    vector<P> t;
    // 0オリジン
    REP(i, n)
    {
        cin >> x >> y;
        t.push_back(make_pair(x, y));
    }

    // 順列の探索
    vector<int> index;
    REP(i, n)
    index.push_back(i);

    double ans = 0.0;
    do
    {
        double tmp = 0.0;
        FOR(i, 1, n - 1)
        {
            tmp += sqrt((t[index[i]].first - t[index[i - 1]].first) * (t[index[i]].first - t[index[i - 1]].first) + (t[index[i]].second - t[index[i - 1]].second) * (t[index[i]].second - t[index[i - 1]].second));
        }

        ans += tmp;
    } while (next_permutation(index.begin(), index.end()));
    FOR(i, 2, n)
    {
        ans /= i;
    }
    cout << fixed << setprecision(10) << ans << "\n";
    return 0;
}