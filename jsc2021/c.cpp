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
const int MAX = 100000;
const ll INF = 1LL << 60;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b, ans;
    cin >> a >> b;
    ans = 0;
    FORR(i, b - a, 1)
    {
        int tmp = i;
        int j = 1;
        while (tmp < b)
        {
            tmp = j * i;
            if (tmp >= a && i * (j + 1) <= b)
            {
                ans = i;
                break;
            }
            j++;
        }
        if (ans > 0)
            break;
    }

    cout << ans << "\n";
    return 0;
}