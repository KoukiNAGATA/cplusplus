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
    ll n;
    cin >> n;

    for (int i = 0; i < (1 << n); i++)
    {
        string s;
        for (int j = 0; j < n; j++)
        {
            // 1ならば')', 0ならば'('とする。
            if (i & (1 << j))
            {
                s.push_back(')');
            }
            else
            {
                s.push_back('(');
            }
        }
        // 辞書順(頭が小さいよう)に並び替え
        reverse(s.begin(), s.end());
        // 括弧列かどうかを判定。
        int pointer = 0;
        bool flag = true;
        REP(i, n)
        {
            if (s[i] == '(')
            {
                ++pointer;
            }
            else
            { // s[i] == ')'
                if (pointer)
                    --pointer;
                else
                    flag = false;
            }
        }
        // どちらの括弧も余っていない
        if (flag && pointer == 0)
            cout << s << "\n";
    }
    return 0;
}