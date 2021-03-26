#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i <= n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
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
    int a, b, w;
    cin >> a >> b >> w;
    int m = 1e9, M = 0;
    for (int n = 1; n <= 1000000; n++)
    {
        if (a * n <= 1000 * w && 1000 * w <= b * n)
        {
            m = min(m, n);
            M = max(M, n);
        }
    }
    if (M == 0)
        cout << "UNSATISFIABLE";
    else
        cout << m << ' ' << M;
    return 0;
}