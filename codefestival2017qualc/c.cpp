// 回文のポインタ
#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define inf 1000000007
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

int solve(string S)
{
    int res = 0;
    // 二重のfor文
    for (int i = 0, j = S.size() - 1; i < j;)
    {
        if (S[i] == S[j])
            ++i, --j;
        else if (S[i] == 'x')
            ++res, ++i;
        else if (S[j] == 'x')
            ++res, --j;
        else
            return -1;
    }
    return res;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int ans = 0;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}