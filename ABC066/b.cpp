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

bool solve(string S)
{
    for (int i = 0; i < S.size() / 2; i++)
    {
        if (S[i] != S[i + S.size() / 2])
            return false;
        else
            continue;
    }
    return true;
}

int main()
{
    // cin高速化
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    // 2文字ずつ消す
    s.erase(s.size() - 2);
    while (s.size() > 0)
    {
        if (solve(s))
            break;
        else
            s.erase(s.size() - 2);
    }
    cout << s.size() << "\n";
    return 0;
}