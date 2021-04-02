#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0; i < n; i++)
#define REPR(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (ll i = m; i <= n; i++)
#define FORR(i, m, n) for (ll i = m; i >= n; i--)
#define SORT(v, n) sort(v, v + n)
#define MAX 100000
#define mod 1000000007
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
using Grid = vector<vector<bool>>;

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt_left = 0;
    int pointer = 0;
    // 左から足りない"(", 右から足りない")"を埋めることで正しい括弧列となる
    REP(i, n)
    {
        if (s[i] == '(')
        {
            ++pointer;
        }
        else
        { // s[i] == ')'
            if (pointer == 0)
                ++cnt_left;
            else
                --pointer;
        }
    }
    int cnt_right = pointer;

    string res = "";
    REP(i, cnt_left)
    res += '(';
    res += s;
    REP(i, cnt_right)
    res += ')';
    cout << res << "\n";
    return 0;
}
