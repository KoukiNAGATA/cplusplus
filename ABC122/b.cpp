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
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;

    REP(i, n)
    {
        FOR(j, i, n - 1)
        {
            int cnt = 0;
            bool flag = false;
            FOR(k, i, j)
            {
                if (s[k] == 'A' || s[k] == 'C' || s[k] == 'G' || s[k] == 'T')
                {
                    ++cnt;
                    continue;
                }
                flag = true;
            }
            if (flag)
                continue;
            ans = max(ans, cnt);
        }
    }
    cout << ans << "\n";
    return 0;
}
