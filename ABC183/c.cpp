// 順列はnext_permutation
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> t(n, vector<int>(n));
    // 0オリジン
    REP(i, n)
    REP(j, n)
    cin >> t[i][j];

    // 順列の探索
    vector<int> index;
    REP(i, n)
    index.push_back(i);

    int ans = 0;
    do
    {
        int time = 0;
        REP(i, n)
        time += t[index[i]][index[(i + 1) % n]];
        if (time == k)
            ans++;
    } while (next_permutation(index.begin() + 1, index.end()));
    cout << ans << "\n";
    return 0;
}