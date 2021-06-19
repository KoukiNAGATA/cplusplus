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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h + 1, vector<int>(w + 1, 0));
    // 行の和
    vector<int> r(h + 1, 0);
    // 列の和
    vector<int> c(w + 1, 0);
    //input
    FOR(i, 1, h)
    {
        FOR(j, 1, w)
        {
            cin >> a[i][j];
            r[i] += a[i][j];
            c[j] += a[i][j];
        }
    }
    // output
    FOR(i, 1, h)
    {
        FOR(j, 1, w)
        {
            cout << r[i] + c[j] - a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}